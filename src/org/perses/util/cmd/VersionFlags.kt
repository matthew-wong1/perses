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
package org.perses.util.cmd

import com.beust.jcommander.Parameter
import org.perses.version.VersionHelper
import java.io.PrintStream

class VersionFlags : ICommandLineFlags {

  @JvmField
  @Parameter(
    names = ["--version"],
    description = "print the version",
    help = true,
    order = CommonCmdOptionGroupOrder.HELP + 1
  )
  var version = false

  override fun validate() = Unit

  fun printVersionInfo(programName: String, stream: PrintStream) {
    VersionHelper.printVersionInfo(programName, stream)
  }
}
