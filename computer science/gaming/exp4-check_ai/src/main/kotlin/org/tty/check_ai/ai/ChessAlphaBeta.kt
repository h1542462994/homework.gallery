package org.tty.check_ai.ai

class ChessAlphaBeta: AlphaBeta<ChessState, ChessAction>() {
    override fun evaluate(state: ChessState): Int {
        return state.evaluate()
    }

    override fun evaluate(a: Int, b: Int, depth: Int, prevState: ChessState, action: ChessAction): Int {
        val newState = migrate(prevState, action)
        return if (newState.winner() != 0) {
            8888
        } else {
            -iter(-b, -a, depth - 1, newState).second
        }
    }

    override fun availableActions(state: ChessState): List<ChessAction> {
        return state.board.availableActions(state.role)
    }

    override fun migrate(state: ChessState, action: ChessAction): ChessState {
        return state.migrate(action)
    }
}