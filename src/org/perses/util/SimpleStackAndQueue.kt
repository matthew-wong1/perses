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

import com.google.common.base.MoreObjects

abstract class AbstractStackOrQueue<T, Self : AbstractStackOrQueue<T, Self>>(
  initialCapacity: Int
) {

  protected val deque = if (initialCapacity > 0) {
    ArrayDeque<T>(initialCapacity)
  } else {
    ArrayDeque()
  }

  abstract fun add(element: T): Self

  abstract fun remove(): T

  abstract fun peek(): T

  val size: Int
    get() = deque.size

  /**
   * Add the elements to this object from the head to the tail.
   */
  fun addAll(elements: Iterable<T>): Self {
    elements.forEach { add(it) }
    @Suppress("UNCHECKED_CAST")
    return this as Self
  }

  fun isEmpty() = deque.isEmpty()

  fun isNotEmpty() = !isEmpty()

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("deque", deque).toString()
  }
}

class SimpleStack<T>(
  initialCapacity: Int = 0
) : AbstractStackOrQueue<T, SimpleStack<T>>(initialCapacity) {

  override fun add(element: T): SimpleStack<T> {
    deque.addLast(element)
    return this
  }

  override fun remove(): T {
    return deque.removeLast()
  }

  override fun peek(): T {
    return deque.last()
  }
}

class SimpleQueue<T>(
  initialCapacity: Int = 0
) : AbstractStackOrQueue<T, SimpleQueue<T>>(initialCapacity) {

  override fun add(element: T): SimpleQueue<T> {
    deque.addLast(element)
    return this
  }

  override fun remove(): T {
    return deque.removeFirst()
  }

  override fun peek(): T {
    return deque.first()
  }
}
