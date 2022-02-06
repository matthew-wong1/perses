/*
 * Copyright (C) 2018-2022 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.reduction

import com.google.common.base.Stopwatch
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.EnumFormatControl.ORIG_FORMAT
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.reduction.io.RegularReductionInputs
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.TimeUtil
import java.io.ByteArrayOutputStream
import java.io.PrintStream
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import java.util.ArrayList
import java.util.concurrent.Future
import java.util.concurrent.TimeUnit
import java.util.function.Consumer

/** Test for [TestScriptExecutorService]  */
@RunWith(JUnit4::class)
class TestScriptExecutorServiceTest {
  companion object {
    private const val FOLDER = "test_data/delta_1/"
  }

  private val sourceFile = SourceFile(Paths.get(FOLDER, "t.c"), LanguageC)
  private val invalidSourceFile = SourceFile(Paths.get("test_data/misc/t1.c"), LanguageC)
  private val testScript = ScriptFile(Paths.get(FOLDER, "r.sh"))
  private val slowTestScript = ScriptFile(Paths.get(FOLDER, "slow_r.sh"))
  private val program = TestUtility.createSparTreeFromFile(sourceFile.file).programSnapshot

  private val workingDirectory =
    TestUtility.createCleanWorkingDirectory(TestScriptExecutorServiceTest::class.java)
  private val outputManagerFactory = RegularOutputManagerFactory(
    sourceFile.baseName,
    ORIG_FORMAT
  )

  private val outputDir = workingDirectory.resolve("perses_output_dir")

  @After
  fun teardown() {
    if (Files.exists(workingDirectory)) {
      // Just to make sure to release the resources.
      MoreFiles.deleteRecursively(
        workingDirectory,
        RecursiveDeleteOption.ALLOW_INSECURE
      )
    }
  }

  @Test
  fun testThreadCount_1() {
    testTestScriptExecutor(threadCount = 1)
  }

  @Test
  fun testThreadCount_4() {
    testTestScriptExecutor(threadCount = 4)
  }

  @Test
  fun test_testScriptExecutionMonitor() {
    val oldSysout = System.out
    val oldSyserr = System.err
    val byteArrayOutputStream = ByteArrayOutputStream()
    val newOut = PrintStream(
      byteArrayOutputStream,
      /*auto_flush=*/true,
      StandardCharsets.UTF_8.name()
    )
    System.setOut(newOut)
    System.setErr(newOut)
    try {
      val reductionInputs = RegularReductionInputs(slowTestScript, sourceFile)
      val ioManager = TokenReductionIOManager(
        workingFolder = workingDirectory,
        reductionInputs = reductionInputs,
        outputManagerFactory = outputManagerFactory,
        outputDirectory = outputDir
      )
      TestScriptExecutorService(
        ioManager.createReductionFolderManager(),
        1,
        scriptExecutionMonitorIntervalMillis = TimeUtil.toMillisFromSeconds(1)
      ).use {
        it.testProgramAsync(
          ALWAYS_TRUE_PRECHECK,
          IDENTITY_POST_CHECK,
          outputManagerFactory.createManagerFor(program)
        ).get()
      }
      newOut.flush()
      val stdout = byteArrayOutputStream.toString(StandardCharsets.UTF_8.name())
      assertThat(stdout).contains(TestScriptExecutorService.MSG_SCRIPT_RUN_TOO_LONG)
    } finally {
      System.setOut(oldSysout)
      System.setErr(oldSyserr)
    }
  }

  private fun testTestScriptExecutor(threadCount: Int) {
    val stopwatch = Stopwatch.createStarted()
    val reductionInputs = RegularReductionInputs(testScript, sourceFile)
    val ioManager = TokenReductionIOManager(
      workingDirectory,
      reductionInputs,
      outputManagerFactory = RegularOutputManagerFactory(
        sourceFile.baseName,
        ORIG_FORMAT
      ),
      outputDirectory = outputDir
    )
    TestScriptExecutorService(
      ioManager.createReductionFolderManager(),
      threadCount,
      scriptExecutionMonitorIntervalMillis = TimeUtil.toMillisFromMinutes(4)
    ).use {
      // TODO: refine this test.
      testPassing(it)
      testFailing(it)
      testPrecheckFailing(it)
      testpostCheckPassing(it)
      stopwatch.stop()
      println(
        "#threads=" + threadCount + ": time=" + stopwatch.elapsed(TimeUnit.SECONDS) + " seconds"
      )
    }
  }

  private fun testpostCheckPassing(service: TestScriptExecutorService) {
    val invalidProgram = TestUtility.createSparTreeFromFile(invalidSourceFile.file)
      .programSnapshot
    val futureList: MutableList<Future<PropertyTestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        service.testProgramAsync(
          ALWAYS_TRUE_PRECHECK,
          { PropertyTestResult(exitCode = 0, elapsedMilliseconds = 1) },
          outputManagerFactory.createManagerFor(invalidProgram)
        )
      )
    }
    futureList.forEach {
      assertThat(it.get().isInteresting).isTrue()
    }
  }

  private fun testPrecheckFailing(service: TestScriptExecutorService) {
    val invalidProgram = TestUtility.createSparTreeFromFile(invalidSourceFile.file)
      .programSnapshot
    val futureList: MutableList<Future<PropertyTestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        service.testProgramAsync(
          { PropertyTestResult(exitCode = 1, elapsedMilliseconds = 1) },
          IDENTITY_POST_CHECK,
          outputManagerFactory.createManagerFor(invalidProgram)
        )
      )
    }
    futureList.forEach {
      assertThat(it.get().isInteresting).isFalse()
    }
  }

  private fun testFailing(it: TestScriptExecutorService) {
    val invalidProgram = TestUtility.createSparTreeFromFile(invalidSourceFile.file)
      .programSnapshot
    val futureList: MutableList<Future<PropertyTestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        it.testProgramAsync(
          ALWAYS_TRUE_PRECHECK,
          IDENTITY_POST_CHECK,
          outputManagerFactory.createManagerFor(invalidProgram)
        )
      )
    }
    futureList.forEach(
      Consumer {
        try {
          assertThat(it.get().isInteresting).isFalse()
        } catch (e: Throwable) {
          throw AssertionError(e)
        }
      }
    )
  }

  private fun testPassing(service: TestScriptExecutorService) {
    val futureList: MutableList<Future<PropertyTestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        service.testProgramAsync(
          ALWAYS_TRUE_PRECHECK,
          IDENTITY_POST_CHECK,
          outputManagerFactory.createManagerFor(program)
        )
      )
    }
    futureList.forEach(
      Consumer {
        try {
          assertThat(it.get().isInteresting).isTrue()
        } catch (e: Throwable) {
          throw AssertionError(e)
        }
      }
    )
  }
}
