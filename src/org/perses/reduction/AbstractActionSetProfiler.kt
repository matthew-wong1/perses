package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.tree.spar.ChildHoistingAction
import java.io.BufferedWriter
import java.io.File
import java.io.IOException
import java.nio.charset.StandardCharsets
import java.nio.file.Files

abstract class AbstractActionSetProfiler {
  abstract fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
    kleeneReplacements: ImmutableList<ChildHoistingAction>
  )

  abstract fun onReplaceNodeWithNearestCompatibleChildren(
    replacements: ImmutableList<ChildHoistingAction>
  )

  class ActionSetProfiler(file: File) : AbstractActionSetProfiler(), AutoCloseable {
    private var writer: BufferedWriter?
    override fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
      kleeneReplacements: ImmutableList<ChildHoistingAction>
    ) {
      try {
        writer!!
          .append("onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren: size=")
          .append(kleeneReplacements.size.toString())
          .append('\n')
          .flush()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    override fun onReplaceNodeWithNearestCompatibleChildren(
      replacements: ImmutableList<ChildHoistingAction>
    ) {
      try {
        writer!!
          .append("onReplaceNodeWithNearestCompatibleChildren: size=")
          .append(replacements.size.toString())
          .append('\n')
          .flush()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    override fun close() {
      try {
        val local = writer
        writer = null
        local?.close()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    init {
      writer = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8)
      Runtime.getRuntime().addShutdownHook(Thread(Runnable { close() }))
    }
  }

  companion object {
    val NULL_PROFILER = object : AbstractActionSetProfiler() {
      override fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
        kleeneReplacements: ImmutableList<ChildHoistingAction>
      ) {
      }

      override fun onReplaceNodeWithNearestCompatibleChildren(
        replacements: ImmutableList<ChildHoistingAction>
      ) {
      }
    }
  }
}
