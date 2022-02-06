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
package org.perses.util

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.util.Random

@RunWith(JUnit4::class)
class PersesKtExtsTest {

  @Test
  fun testImmutableListPlus() {
    val list1 = ImmutableList.of(1)
    val list2 = ImmutableList.of(2)
    val plus: ImmutableList<Int> = list1 + list2 // The type has to be ImmutableList
    assertThat(plus).containsExactly(1, 2)
  }

  @Test
  fun testForEachElementAndGapOnEmptyList() {
    val list = listOf<String>()
    var elementCounter = 0
    var gapCounter = 0
    list.forEachElementAndGap(
      elementVisitor = { ++elementCounter },
      gapVisitor = { ++gapCounter }
    )
    assertThat(elementCounter).isEqualTo(0)
    assertThat(gapCounter).isEqualTo(0)
  }

  @Test
  fun testForEachElementAndGapOnSingleElement() {
    val list = listOf(1)
    val elements = ArrayList<Int>()
    var gapCounter = 0
    list.forEachElementAndGap(
      elementVisitor = { elements.add(it) },
      gapVisitor = { ++gapCounter }
    )
    assertThat(elements).containsExactly(1)
    assertThat(gapCounter).isEqualTo(0)
  }

  @Test
  fun testForEachElementAndGapOnMultipleElements() {
    val list = listOf("1", "2", "3")
    val sequence = StringBuilder()
    list.forEachElementAndGap(
      elementVisitor = { sequence.append(it) },
      gapVisitor = { sequence.append(",") }
    )
    assertThat(sequence.toString()).isEqualTo("1,2,3")
  }

  @Test
  fun testSampleFromList() {
    val list = listOf(1, 2, 3, 4, 5)

    val intRange = 0..5

    val result1 = Random(1).let { r1 ->
      intRange.asSequence().map { r1.sample(list) }.toList()
    }

    val result2 = Random(1).let { r2 ->
      intRange.asSequence().map { list[r2.nextInt(list.size)] }.toList()
    }

    assertThat(result1).isEqualTo(result2)
  }

  @Test
  fun testRemoveWhitespaces() {
    java.lang.StringBuilder().apply { append(" c ") }.let {
      assertThat(it.removeWhitespaces().toString()).isEqualTo("c")
      assertThat(it.toString()).isEqualTo(" c ")
    }
  }

  @Test
  fun testContainsNoWhitespace() {
    assertThat("a".containsNoWhitespace()).isTrue()
    assertThat(" ".containsNoWhitespace()).isFalse()
    assertThat("\n".containsNoWhitespace()).isFalse()
    assertThat("".containsNoWhitespace()).isTrue()
  }
}
