package org.tty.check_ai.ai

import org.tty.check_ai.data.Board
import org.tty.check_ai.data.Values

data class ChessState(
    val board: Board,
    val role: Int
){
    fun evaluate(): Int {
        var value = 0

        board.cheeses.forEach {
            val (point, key) = it
            val (x, y) = point
            value += Values.getNamed(key)[x, y]
        }
        return value
    }

    fun winner(): Int {
        if (board.cheeses.find { it.second == "j" } == null) {
            return 1
        } else if (board.cheeses.find { it.second == "J" } == null) {
            return -1
        } else {
            return 0
        }
    }

    fun migrate(action: ChessAction): ChessState {
        TODO("not implemented yet")
    }

    fun my(key: String): Int {
        return if (key[0].isLowerCase()) {
            role
        } else {
            -role
        }
    }
}