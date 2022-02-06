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
package org.perses.antlr.pnf

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility

@RunWith(JUnit4::class)
class InlineFragmentPassTest {

  val pass = InlineFragmentPass()

  @Test
  fun testSimpleCase() {
    val g = GrammarTestingUtility.createPersesGrammarFromString(
      """
      fragment F2 : 'a' ;
      fragment F1 : F2 ;
      T1 : F1 ;  
      """.trimIndent()
    )
    val rules = pass.process(g).flattenedAllRules
    assertThat(rules).hasSize(1)
    val rule = rules.single()
    assertThat(rule.ruleNameHandle.ruleName).isEqualTo("T1")
    assertThat(rule.body.sourceCode).isEqualTo("'a'")
  }

  @Test
  fun testInliningAltblock() {
    val g = GrammarTestingUtility.createPersesGrammarFromString(
      """
        fragment EncodingPrefix 
          : 'u8' | 'u' ;
        
        fragment SCharSequence
          : 'a' + ;
    
        StringLiteral 
          : EncodingPrefix? '"' SCharSequence?  '"' ;
       
      """.trimIndent()
    )
    val rules = pass.process(g).flattenedAllRules
    assertThat(rules).hasSize(1)
    val rule = rules.single()
    assertThat(rule.ruleNameHandle.ruleName).isEqualTo("StringLiteral")
    assertThat(rule.body.sourceCode).isEqualTo(""" ('u8' | 'u')? '"' 'a'* '"'  """.trim())
  }
}
