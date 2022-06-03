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
package org.perses.reduction.io

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.Joiner
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.program.SourceFile
import org.perses.util.AutoIncrementDirectory
import org.perses.util.TimeUtil
import org.perses.util.Util
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import java.nio.file.StandardCopyOption
import java.time.LocalDateTime
import java.util.concurrent.atomic.AtomicInteger

abstract class AbstractReductionIOManager
<P, Self : AbstractReductionIOManager<P, Self>>(
  protected val workingFolder: Path,
  val reductionInputs: AbstractReductionInputs,
  val outputManagerFactory: AbstractOutputManagerFactory<P>,
  outputDirectory: Path?
) {

  val tempRootFolder = getTempRootFolderPath(
    workingFolder,
    reductionInputs.relativePathSequence().asIterable(),
    reductionInputs.testScript.file.fileName.toString(),
    LocalDateTime.now()
  )

  abstract fun getConcreteReductionInputs(): AbstractReductionInputs

  protected val resultFolder = if (outputDirectory == null) {
    val dir = AutoIncrementDirectory(DEFAULT_PERSES_BEST_DIR_NAME)
      .computeAndCreate(workingFolder)
    ReductionFolder(reductionInputs, dir)
  } else {
    if (!Files.exists(outputDirectory)) {
      Files.createDirectories(outputDirectory)
    }
    check(Files.isDirectory(outputDirectory)) {
      "$outputDirectory is not a directory."
    }
    ReductionFolder(reductionInputs, outputDirectory)
  }

  fun updateBestResult(program: P) {
    /*
     * We try to make the writing-best-resut operation atomic.
     */
    val tempDirectory = createTempResultFolder()
    createOutputManager(program).write(tempDirectory)
    Util.copyDirectory(
      tempDirectory.folder,
      resultFolder.folder,
      StandardCopyOption.REPLACE_EXISTING
    )
    MoreFiles.deleteRecursively(tempDirectory.folder, RecursiveDeleteOption.ALLOW_INSECURE)
  }

  private val tempFolderCounter = AtomicInteger(0)
  fun createTempResultFolder(): ReductionFolder {
    val tempRootFolder = materializeTempRootFolder()
    val tempResultFolder = tempRootFolder.resolve(
      "temp_${tempFolderCounter.getAndIncrement()}_${System.currentTimeMillis()}"
    )
    Files.createDirectory(tempResultFolder)
    return ReductionFolder(reductionInputs, tempResultFolder)
  }

  fun createOutputManager(program: P): AbstractOutputManager {
    return outputManagerFactory.createManagerFor(program)
  }

  fun getScriptFileBaseNameIn(folder: ReductionFolder): String {
    val scriptBaseName = reductionInputs.testScript.baseName
    check(folder.checkFileExistence(scriptBaseName))
    return scriptBaseName
  }

  fun getSingleSourceFileBaseName(folder: ReductionFolder): String {
    val fileNames = reductionInputs.relativePathSequence().toList()
    check(fileNames.size == 1)
    val baseName = fileNames.first().toString()
    check(folder.checkFileExistence(baseName))
    return baseName
  }

  inline fun <T> visitMainSourceFileIn(
    reductionFolder: ReductionFolder,
    visitor: (SourceFile) -> T
  ): T {
    return visitor.invoke(
      SourceFile(
        reductionFolder.folder.resolve(getSingleSourceFileBaseName(reductionFolder)),
        reductionInputs.mainLanguage
      )
    )
  }

  fun getProfileFile() = workingFolder.resolve(
    getCompactNameForFileList(reductionInputs.relativePathSequence().asIterable()) + "." +
      TimeUtil.formatDateForFileName(System.currentTimeMillis()) + ".profile.txt"
  )

  fun backupMainFile(): ImmutableList<Path> {
    val formatDateForFileName = TimeUtil.formatDateForFileName(System.currentTimeMillis())
    return reductionInputs.orig2relativePathPairs
      .asSequence()
      .map {
        val fileToReduce = it.origFile
        val relativePath = it.relativePath
        val backupFile = workingFolder.resolve(
          "$relativePath.$formatDateForFileName.orig"
        )
        check(!Files.exists(backupFile)) {
          "The backup file $backupFile exists."
        }
        // Note that a file can be a binary file, so it is good to copy the file directly.
        Files.copy(fileToReduce.file, backupFile)
        backupFile
      }.toImmutableList()
  }

  fun materializeTempRootFolder(): Path {
    if (!Files.exists(tempRootFolder)) {
      Files.createDirectory(tempRootFolder)
    }
    check(Files.isDirectory(tempRootFolder)) {
      "The temp root folder is not a directory: $tempRootFolder"
    }
    return tempRootFolder
  }

  fun createReductionFolderManager(): ReductionFolderManager {
    materializeTempRootFolder()
    return ReductionFolderManager(
      reductionInputs = reductionInputs,
      rootFolder = tempRootFolder
    )
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    protected const val PERSES_TEMP_ROOT_PREFIX = "PersesTempRoot"
    protected const val DEFAULT_PERSES_BEST_DIR_NAME = "perses_result"

    fun getCompactNameForFileList(fileList: Iterable<Path>): String {
      return fileList
        .groupBy { it.fileName.toString() }
        .map { (fileName, pathList) ->
          return if (pathList.size < 2) {
            fileName
          } else {
            return "${fileName}${pathList.size}"
          }
        }.joinToString("_")
    }

    @JvmStatic
    @VisibleForTesting
    fun getTempRootFolderName(
      fileNameForReduction: Iterable<Path>,
      testScriptName: String?,
      time: LocalDateTime
    ): String {
      val separator = "_"
      val fileListString = getCompactNameForFileList(fileNameForReduction)
      return Joiner.on(separator)
        .join(
          PERSES_TEMP_ROOT_PREFIX,
          fileListString,
          testScriptName,
          TimeUtil.formatDateForFileName(time)
        )
    }

    @JvmStatic
    fun getTempRootFolderPath(
      workingFolder: Path,
      fileNameForReduction: Iterable<Path>,
      testScriptName: String?,
      time: LocalDateTime
    ): Path {
      val name = getTempRootFolderName(fileNameForReduction, testScriptName, time)
      val tmpdir = System.getenv("TMPDIR")
      return if (tmpdir != null) {
        Paths.get(tmpdir, name)
      } else {
        workingFolder.resolve(name)
      }
    }
  }

  init {
    require(Files.exists(workingFolder)) {
      "The working folder does not exist: $workingFolder"
    }
    require(Files.isDirectory(workingFolder)) {
      "The working folder is not a directory: $workingFolder"
    }
  }
}
