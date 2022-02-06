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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.util.cmd.CommonCmdOptionGroupOrder
import org.perses.util.cmd.ICommandLineFlags

class ReductionAlgorithmControlFlags(val defaultReductionAlgorithm: String) :
  ICommandLineFlags {
  @JvmField
  @Parameter(
    names = ["--alg"],
    description = "reduction algorithm: use --list-algs to list all available algorithms",
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 0
  )
  var reductionAlgorithm: String? = null

  @JvmField
  @Parameter(
    names = ["--list-algs"],
    description = "list all the reduction algorithms.",
    help = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 1
  )
  var listAllReductionAlgorithms = false

  @Parameter(
    names = ["--reparse-each-iteration"],
    description = "Reparse the program before the start of each fixpoint iteration.",
    arity = 1,
    hidden = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 2
  )
  var rebuildParseTreeEachIteration = true

  @Parameter(
    names = ["--enable-token-slicer"],
    description = "Enable token slicer after syntax-guided reduction is done. Maybe slow.",
    arity = 1,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 3
  )
  var enableTokenSlicer = false

  @Parameter(
    names = ["--enable-tree-slicer"],
    description = "Enable tree slicer after syntax-guided reduction, and before token slicer",
    arity = 1,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 4
  )
  var enableTreeSlicer = false

  @Parameter(
    names = ["--enable-line-slicer"],
    description = "Enable line slicer after syntax-guided reduction, and before token slicer",
    arity = 1,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 5
  )
  var enableLineSlicer = false

  @Parameter(
    names = ["--use-real-ddmin"],
    description = "Whether to use the real delta debugging algorithm to reduce kleene nodes.",
    arity = 1,
    hidden = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 6
  )
  var useRealDeltaDebugger = false

  @JvmField
  @Parameter(
    names = ["--use-optc-parser"],
    description = "Use the OptC parser to construct the spar-tree.",
    arity = 1,
    hidden = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 7
  )
  var useOptCParser = false

  @JvmField
  @Parameter(
    names = ["--max-edit-count-for-regular-rule-node"],
    description = "The max count of edit candidates for reducing a regular rule node.",
    arity = 1,
    hidden = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 9
  )
  var maxEditCountForRegularRuleNode = 100

  @JvmField
  @Parameter(
    names = ["--max-bfs-depth-for-regular-rule-node"],
    description = "The max count of edit candidates for reducing a regular rule node.",
    arity = 1,
    hidden = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 10
  )
  var maxBfsDepthForRegularRuleNode = 5

  @JvmField
  @Parameter(
    names = ["--stop-at-first-compatible-child-for-regular-rule-node"],
    description = "The max count of edit candidates for reducing a regular rule node.",
    arity = 1,
    hidden = true,
    order = CommonCmdOptionGroupOrder.ALG_CONTROL + 11
  )
  var stopAtFirstCompatibleChildForRegularRuleNode = false

  fun getReductionAlgorithmName(): String {
    if (reductionAlgorithm.isNullOrEmpty()) {
      reductionAlgorithm = defaultReductionAlgorithm
    }
    return checkNotNull(reductionAlgorithm)
  }

  override fun validate() {
  }
}
