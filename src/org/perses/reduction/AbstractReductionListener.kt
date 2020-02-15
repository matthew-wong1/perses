/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import org.perses.reduction.AbstractReductionEvent.*

/** The listener to access the internal reduction state.  */
abstract class AbstractReductionListener {
  /** Called on the start of the reduction.  */
  abstract fun onReductionStart(event: ReductionStartEvent?)

  /** Called on the end of the reduction.  */
  abstract fun onReductionEnd(event: ReductionEndEvent?)

  /** Called on the start of a fixpoint iteration.  */
  abstract fun onFixpointIterationStart(event: FixpointIterationStartEvent?)

  /** Called on the end of a fixpoint iteration  */
  abstract fun onFixpointIterationEnd(
      event: FixpointIterationEndEvent?)

  abstract fun onLevelReductionStart(event: LevelReductionStartEvent?)
  abstract fun onLevelReductionEnd(event: LevelReductionEndEvent?)
  abstract fun onLevelGranularityReductionStart(
      event: LevelGranularityReductionStartEvent?)

  abstract fun onLevelGranularityReductionEnd(
      event: LevelGranularityReductionEndEvent?)

  abstract fun onNodeReductionStart(event: NodeReductionStartEvent?)
  abstract fun onNodeReductionEnd(event: NodeReductionEndEvent?)
  abstract fun onTestScriptExecutionCacheEntryEviction(
      event: TestScriptExecutionCacheEntryEvictionEvent?)

  abstract fun onNodeActionSetCacheClearance(event: NodeEditActionSetCacheClearanceEvent?)
  abstract fun onTestScriptExecution(event: TestScriptExecutionEvent?)
  abstract fun onTestResultCacheHit(event: TestResultCacheHitEvent?)
  abstract fun onNodeEditActionSetCacheHit(
      event: NodeEditActionSetCacheHitEvent?)

  abstract fun onTestScriptExecutionCancelled(
      event: TestScriptExecutionCanceledEvent?)
}