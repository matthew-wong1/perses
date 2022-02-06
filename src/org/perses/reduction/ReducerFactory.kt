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

import com.google.common.base.Functions
import com.google.common.collect.ImmutableCollection
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import org.perses.reduction.reducer.PersesNodeBfsReducer
import org.perses.reduction.reducer.PersesNodeDfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedBfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.reduction.reducer.TreeSlicer
import org.perses.reduction.reducer.hdd.HDDReducer
import org.perses.reduction.reducer.hdd.PristineHDDReducer
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.reduction.reducer.token.DeltaDebuggingReducer
import org.perses.reduction.reducer.token.LineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.token.TokenSlicer

/** Factory to create various reducers.  */
object ReducerFactory {
  private val DEFAULT_REDUCTION_ALG = PersesNodePrioritizedDfsReducer.META

  private val REDUCTION_ALGs = ImmutableSet.builder<ReducerAnnotation>()
    .add(HDDReducer.META)
    .add(TokenSlicer.META)
    .addAll(ConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
    .add(ConcurrentTokenSlicer.COMPOSITE_REDUCER)
    .addAll(LineBasedConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
    .add(LineBasedConcurrentTokenSlicer.COMPOSITE_REDUCER)
    .add(TreeSlicer.META)
    .add(PersesNodeBfsReducer.META)
    .add(PersesNodePrioritizedBfsReducer.META)
    .add(PersesNodeDfsReducer.META)
    .add(PristineHDDReducer.META)
    .add(DeltaDebuggingReducer.META)
    .add(DEFAULT_REDUCTION_ALG)
    .build()
    .stream()
    .collect(
      ImmutableMap.toImmutableMap(
        { obj: ReducerAnnotation -> obj.shortName() },
        Functions.identity()
      )
    )

  @JvmStatic
  val defaultReductionAlgName: String
    get() {
      val defaultAlgName = PersesNodePrioritizedDfsReducer.NAME
      assert(isValidReducerName(defaultAlgName))
      return defaultAlgName
    }

  @JvmStatic
  fun getAnnotationWithName(algorithmName: String): ReducerAnnotation? {
    return REDUCTION_ALGs[algorithmName]
  }

  @JvmStatic
  fun isValidReducerName(shortName: String) = REDUCTION_ALGs.containsKey(shortName)

  @JvmStatic
  val allReducerAlgorithms: ImmutableCollection<ReducerAnnotation>
    get() = REDUCTION_ALGs.values

  @JvmStatic
  fun getReductionAlgorithm(reducerShortName: String): ReducerAnnotation {
    val annotation = getAnnotationWithName(reducerShortName)
    requireNotNull(annotation) {
      "Cannot find annotation for the name $reducerShortName"
    }
    return annotation
  }

  @JvmStatic
  fun printAllReductionAlgorithms(): String {
    val builder = StringBuilder()
    val algorithms: ImmutableList<ReducerAnnotation> = REDUCTION_ALGs.values.stream()
      .sorted(Comparator.comparing { obj: ReducerAnnotation -> obj.shortName() })
      .collect(ImmutableList.toImmutableList())
    var i = 0
    val size = algorithms.size
    while (i < size) {
      val algorithm = algorithms[i]
      builder.append(i + 1).append(". ").append(algorithm.shortName()).append(":\n")
      builder.append("    ")
      val description = algorithm.description().replace('\n', ' ')
      builder.append(description).append('\n')
      ++i
    }
    return builder.toString()
  }
}
