package org.tty.check_ai.data

interface Consumer2<T> {
    fun action(rowIndex: Int, columnIndex: Int, data: T)
}