package org.tty.check_ai.ai

abstract class AlphaBeta<TState, TAction> {


    fun run(a: Int = Int.MIN_VALUE, b: Int = Int.MAX_VALUE, depth: Int, state: TState): Pair<TAction?, Int> {
        require(depth >= 0) {
            "depth is invalid"
        }
        return iter(a, b, depth, state)
    }

    protected fun iter(a: Int, b: Int, depth: Int, state: TState): Pair<TAction?, Int> {
        if (depth == 0) {
            return Pair(null, evaluate(state))
        }
        val actions = availableActions(state)
        var maxAction: TAction? = null
        var maxValue = Int.MIN_VALUE

        actions.forEach { action ->
            val current = evaluate(a, b, depth, state, action)
            if (current > maxValue) {
                maxAction = action
                maxValue = current
            }
        }

        return Pair(maxAction, maxValue)
    }

    abstract fun evaluate(state: TState): Int
    abstract fun evaluate(a: Int, b: Int, depth: Int, prevState: TState, action: TAction): Int
    abstract fun availableActions(state: TState): List<TAction>
    abstract fun migrate(state: TState, action: TAction): TState
}