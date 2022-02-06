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
package org.perses.antlr

import com.google.common.collect.ImmutableList
import com.google.common.io.Files.getNameWithoutExtension
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.util.AntlrToolWrapper
import org.perses.util.FileNameContentPair
import org.perses.util.Util
import org.perses.util.java.JarFile
import org.perses.util.java.JarPackager
import org.perses.util.java.JavacWrapper
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption
import java.util.zip.ZipOutputStream
import kotlin.io.path.writeText

class AntlrCompiler(
  val parser: PersesGrammar,
  val lexer: FileNameContentPair?,
  val startRuleName: String,
  val workingDirectory: Path,
  val stubFactory: AbstractGrammarStubFactory,
  val packageName: String,
  val jarFileCustomizer: (ZipOutputStream) -> Unit
) {

  init {
    if (!Files.exists(workingDirectory)) {
      Files.createDirectories(workingDirectory)
    }
    require(Util.isEmptyDirectory(workingDirectory)) { workingDirectory.toAbsolutePath() }
  }

  private val parserFileBaseName = parser.grammarName + ".g4"

  val parserFile: Path = workingDirectory.resolve(parserFileBaseName).apply {
    writeText(parser.sourceCode)
  }

  val lexerFile = if (lexer == null) null else
    workingDirectory.resolve(lexer.fileName).apply {
      writeText(lexer.content)
    }

  val lexerClassSimpleName: String = if (lexer == null)
    parser.grammarName + "Lexer"
  else getNameWithoutExtension(lexer.fileName)

  val parserClassSimpleName = when (parser.grammarType) {
    PersesGrammar.GrammarType.COMBINED -> parser.grammarName + "Parser"
    PersesGrammar.GrammarType.PARSER -> parser.grammarName
    else -> throw RuntimeException("Unreachable. ${parser.grammarType}")
  }
  private val mainStub = stubFactory.createStub(
    packageName = packageName,
    parserClassSimpleName = parserClassSimpleName,
    lexerClassSimpleName = lexerClassSimpleName,
    startRuleName = startRuleName
  )
  val outputFolder: Path = workingDirectory.resolve(packageName.replace('.', '/'))

  private val parserJavaFile: Path = outputFolder.resolve("$parserClassSimpleName.java")
  private val lexerJavaFile: Path = outputFolder.resolve("$lexerClassSimpleName.java")
  private val mainJavaFile: Path = outputFolder.resolve(mainStub.classSimpleName() + ".java")
  val jarFile: Path = outputFolder.resolve(parser.grammarName + ".jar")

  private fun generateJavaCode() {
    AntlrToolWrapper(
      packageName = packageName,
      parserFile = parserFile,
      lexerFile = lexerFile,
      outputDir = outputFolder.toString()
    ).call()

    mainStub.writeTo(mainJavaFile)
    parserFile.let {
      Files.move(it, outputFolder.resolve(it.fileName), StandardCopyOption.REPLACE_EXISTING)
    }
    lexerFile?.let {
      Files.move(it, outputFolder.resolve(it.fileName), StandardCopyOption.REPLACE_EXISTING)
    }
    check(Files.isRegularFile(parserJavaFile)) {
      "$parserJavaFile is not successfully generated."
    }
    check(lexer == null || Files.isRegularFile(lexerJavaFile)) {
      "$lexerJavaFile is not successfully generated."
    }
    check(Files.isRegularFile(mainJavaFile)) {
      "$mainJavaFile is not successfully created."
    }
  }

  private fun compileJavaCode() {
    JavacWrapper(
      ImmutableList.of(
        lexerJavaFile,
        parserJavaFile,
        mainJavaFile
      )
    ).use { it.compile() }
  }

  private fun createJarFile(destination: Path) {
    val packager = JarPackager(
      outputFolder,
      packageName,
      { file ->
        file.endsWith(".java") || file.endsWith(".class") || file.endsWith(".g4")
      },
      jarFileCustomizer
    )
    packager.createJarFile(destination)
  }

  // FIXME: refactor this and make other APIs private.
  fun run(): JarFile {
    generateJavaCode()
    compileJavaCode()
    check(!Files.exists(jarFile))
    createJarFile(jarFile)
    return JarFile(
      path = jarFile,
      mainClassFullName = mainStub.classFullName()
    )
  }

  companion object {
    fun createFromFiles(
      parserFile: Path,
      lexerFile: Path?,
      startRuleName: String,
      workingDirectory: Path,
      stubFactory: AbstractGrammarStubFactory,
      packageName: String,
      jarFileCustomizer: (ZipOutputStream) -> Unit
    ) = AntlrCompiler(
      parser = PersesAstBuilder.loadGrammarFromString(
        Files.readAllBytes(parserFile).toString(StandardCharsets.UTF_8)
      ),
      lexer = if (lexerFile == null) null else
        FileNameContentPair.createFromFile(lexerFile),
      startRuleName = startRuleName,
      workingDirectory = workingDirectory,
      stubFactory = stubFactory,
      packageName = packageName,
      jarFileCustomizer = jarFileCustomizer
    )

    fun createFromStrings(
      parserCode: String,
      lexerFileName: String,
      lexerCode: String,
      startRuleName: String,
      workingDirectory: Path,
      stubFactory: AbstractGrammarStubFactory,
      packageName: String,
      jarFileCustomizer: (ZipOutputStream) -> Unit
    ) = AntlrCompiler(
      parser = PersesAstBuilder.loadGrammarFromString(parserCode),
      lexer = FileNameContentPair(lexerFileName, lexerCode),
      startRuleName = startRuleName,
      workingDirectory = workingDirectory,
      stubFactory = stubFactory,
      packageName = packageName,
      jarFileCustomizer = jarFileCustomizer
    )
  }
}
