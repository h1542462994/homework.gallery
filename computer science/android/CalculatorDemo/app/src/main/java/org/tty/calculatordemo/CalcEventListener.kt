package org.tty.calculatordemo

enum class CalcAction(
    var value: String
){
    AC("ac"),
    DEL("del"),
    EQUAL("=")
}

enum class CalcOperator(
    var value: String
) {
    LEFT("("),
    RIGHT(")"),
    DIVIDE("÷"),
    MULTIPLY("×"),
    SUBTRACT("-"),
    ADD("+")
}

interface CalcEventListener {
    fun onCalcAction(calcAction: CalcAction)
    fun onCalcOperator(calcOperator: CalcOperator)
    fun onNumber(number: Int)
    fun onDot()
}