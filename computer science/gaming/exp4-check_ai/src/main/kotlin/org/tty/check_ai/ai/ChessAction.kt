package org.tty.check_ai.ai

import org.tty.check_ai.data.Point

data class ChessAction (
    val oldPoint: Point,
    val newPoint: Point,
    val key: String
)