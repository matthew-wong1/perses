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

import com.google.common.base.Strings
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.util.Util
import java.nio.file.Files
import java.nio.file.Path
import java.util.concurrent.atomic.AtomicInteger

class ReductionFolderManager internal constructor(
  private val reductionInputs: AbstractReductionInputs,
  val rootFolder: Path
) {
  private val sequenceGenerator = AtomicInteger()

  fun createNextFolder(): ReductionFolder {
    check(!isRootFolderDeleted()) { "The root folder has been deleted." }
    val folderId = sequenceGenerator.getAndIncrement()
    val folderName = Strings.padStart(folderId.toString(), FOLDER_NAME_MIN_LENGTH, '0')
    return createNamedFolder(folderName)
  }

  fun createNamedFolder(folderName: String): ReductionFolder {
    val folder = rootFolder.resolve(folderName)
    check(!Files.exists(folder)) { "The folder already exists. $folder" }
    Files.createDirectory(folder)
    check(Files.isDirectory(folder)) { "Failed to create folder $folder" }
    return ReductionFolder(reductionInputs, folder)
  }

  private fun isRootFolderDeleted() = !Files.exists(rootFolder)

  fun deleteRootFolder() {
    if (isRootFolderDeleted()) {
      return
    }
    MoreFiles.deleteRecursively(rootFolder, RecursiveDeleteOption.ALLOW_INSECURE)
  }

  companion object {
    const val FOLDER_NAME_MIN_LENGTH = 6
  }

  init {
    require(Files.exists(rootFolder)) {
      "The root folder does not exist: $rootFolder"
    }
    require(Files.isDirectory(rootFolder)) {
      "The root folder is not a directory: $rootFolder"
    }
    require(Util.isEmptyDirectory(rootFolder)) {
      "The root folder should be empty: $rootFolder"
    }
  }
}
