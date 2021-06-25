package org.tty.check_ai.data

/**
 * Matrix data class
 */
data class SerialMatrix<T>(
    val rowCount: Int,
    val columnCount: Int,
    var data: List<T>
): Iterable<T> {
    init {
        require(data.size == rowCount * columnCount) {
            "data size is not valid"
        }
    }

    operator fun get(rowIndex: Int, columnIndex: Int): T {
        require(rowIndex in 0 until rowCount) {
            "rowIndex is not valid."
        }
        require(columnIndex in 0 until columnCount) {
            "columnIndex is not valid."
        }

        val serialIndex = rowIndex * columnCount + columnIndex
        return data[serialIndex]
    }

    fun forEachIndexed(consumer: Consumer2<T>) {
        (0 until rowCount).forEach {  rowIndex ->
            (0 until columnCount).forEach {  columnIndex ->
                consumer.action(rowIndex, columnIndex, this[rowIndex, columnIndex])
            }
        }
    }

    companion object {
        fun <T> empty(rowCount: Int, columnCount: Int): SerialMatrix<T> {
            val list = ArrayList<T>(rowCount * columnCount)
            return SerialMatrix(rowCount, columnCount, list)
        }

        fun <T> all(rowCount: Int, columnCount: Int, data: T): SerialMatrix<T> {
            val list = ArrayList<T>(rowCount * columnCount)
            (0 until rowCount * columnCount).forEach { index ->
                list[index] = data
            }
            return SerialMatrix(rowCount, columnCount, list)
        }
    }

    override fun iterator(): Iterator<T> {
        return data.iterator()
    }


}