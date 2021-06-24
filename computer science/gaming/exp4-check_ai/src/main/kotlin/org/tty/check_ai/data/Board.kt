package org.tty.check_ai.data

import org.tty.check_ai.ai.ChessAction

class Board {
    lateinit var matrix: SerialMatrix<String>
    private val rowCount = 10
    private val columnCount = 9

    fun use(token: String) {
        val tokens = token.split(",")
        matrix = SerialMatrix(rowCount, columnCount, tokens)
    }
    val token: String
    get() {
        return matrix.joinToString(",")
    }

    val cheeses: List<Pair<Point, String>>
    get() {
        val list = ArrayList<Pair<Point, String>>()
        matrix.forEachIndexed(object: Consumer2<String> {
            override fun action(rowIndex: Int, columnIndex: Int, data: String) {
                if (data != ""){
                    val key = data[0].toString()
                    list.add(Pair(Point(rowIndex, columnIndex), key))
                }
            }
        })
        return list
    }

    fun availableActions(role: Int): List<ChessAction> {
        return cheeses.filter { roleAt(it.first) == role }.flatMap {
            return actionsOf(it.first)
        }
    }

    fun actionsOf(point: Point): List<ChessAction> {
        val (x, y) = point
        val chess = matrix[x, y]
        if (chess == ""){
            return listOf()
        } else {

            val key = chess[0].toString()
            val key2 = chess[0].toLowerCase().toString()

            return when(key2) {
                "c" -> actionsOfC(point).map {
                    ChessAction(point, it, key)
                }
                "d" -> actionsOfM(point).map {
                    ChessAction(point, it, key)
                }
                else -> error("key not support.")
            }
        }
    }

    // 车
    private fun actionsOfC(point: Point): List<Point> {
        val d = ArrayList<Point>()
        val (x, y) = point
        val myRole = roleAt(point)

        var il = x - 1
        // search left
        while (il >= 0) {
            if (!addStep(d, myRole, Point(il, y))) {
                break
            }
            il -= 1
        }

        il = x + 1
        while (il < columnCount) {
            if (!addStep(d, myRole, Point(il, y))) {
                break
            }
            il -= 1
        }

        il = y - 1
        while (il >= 0) {
            if (!addStep(d, myRole, Point(x, il))) {
                break
            }
            il -= 1
        }

        il = y + 1
        while (il < rowCount) {
            if (!addStep(d, myRole, Point(x, il)))
            il += 1
        }
        return d
    }
    // 马
    private fun actionsOfM(point: Point): List<Point> {
        val d = ArrayList<Point>()
        val (x, y) = point
        val role = roleAt(point)
        addStep(d, role, Point(x+1, y-2))
        addStep(d, role, Point(x+2, y-1))
        addStep(d, role, Point(x+2, y+1))
        addStep(d, role, Point(x+1, y+2))
        addStep(d, role, Point(x-2, y+1))
        addStep(d, role, Point(x-2, y-1))
        addStep(d, role, Point(x-1, y-2))
        return d

    }
    // 相
    private fun actionOfX(point: Point): List<Point> {
        val d = ArrayList<Point>()
        val (x, y) = point
        val role = roleAt(point)
        val topLeft = if (role == 1) {
            Point(0, 0)
        } else {
            Point(8, 4)
        }

        val bottomRight = if (role == 1) {
            Point(0, 5)
        } else {
            Point(8, 9)
        }

        addStepWithRegion(d, role, Point(x+2, y+2), topLeft, bottomRight)
        addStepWithRegion(d, role, Point(x-2, y-2), topLeft, bottomRight)
        addStepWithRegion(d, role, Point(x+2, y-2), topLeft, bottomRight)
        addStepWithRegion(d, role, Point(x-2, y+2), topLeft, bottomRight)
        return d
    }
    // 士
    private fun actionOfS(point: Point): List<Point> {
        val d = ArrayList<Point>()
        val (x, y) = point
        val role = roleAt(point)
        val topLeft = if (role == 1) {
            Point(3, 0)
        } else {
            Point(5, 2)
        }

        val bottomRight = if (role == 1) {
            Point(3, 7)
        } else {
            Point(5, 9)
        }

        addStepWithRegion(d, role, Point(x+1, y+1), topLeft, bottomRight)
        addStepWithRegion(d, role, Point(x-1, y-1), topLeft, bottomRight)
        addStepWithRegion(d, role, Point(x+1, y-1), topLeft, bottomRight)
        addStepWithRegion(d, role, Point(x-1, y+1), topLeft, bottomRight)
        return d
    }

    private fun addStepWithRegion(list: ArrayList<Point>, role: Int, point: Point, topLeft: Point, bottomRight: Point): Boolean {
        val (x, y) = point
        if (x !in topLeft.x .. bottomRight.x) {
            return false
        }
        if (y !in topLeft.y .. bottomRight.y) {
            return false
        }

        return addStep(list, role, point)
    }
    private fun addStep(list: ArrayList<Point>, role: Int, point: Point): Boolean {
        val (x, y) = point
        if (x !in 0 until matrix.columnCount) {
            return false
        }
        if (y !in 0 until matrix.rowCount) {
            return false
        }

        return if (matrix[x, y] != "") {
            val targetRole = roleAt(point)
            if (role != targetRole) {
                list.add(point)
            }
            false
        } else {
            true
        }
    }

    /**
     * 如果是大写，返回1，否则返回-1
     */
    fun role(key: String): Int {
        val keyChar = key[0]
        return if (keyChar.isUpperCase()) {
            1
        } else {
            -1
        }
    }

    private fun roleAt(point: Point): Int {
        val (x, y) = point
        val key = matrix[x, y]
        return if (key == "") {
            0
        } else {
            role(key)
        }
    }

    private fun roleAt(x: Int, y: Int) = roleAt(Point(x, y))

    companion object {
        fun init(): Board {
            val board = Board()
            board.matrix = SerialMatrix(9,10, listOf(
                "C0","M0","X0","S0","J0","S1","X1","M1","C1",
                ""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,
                ""  ,"P0",""  ,""  ,""  ,""  ,""  ,"P1",""  ,
                "Z0",""  ,"Z1",""  ,"Z2",""  ,"Z3",""  ,"Z4",
                ""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,

                ""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,
                "z0",""  ,"z1",""  ,"z2",""  ,"z3",""  ,"z4",
                ""  ,"p0",""  ,""  ,""  ,""  ,""  ,"p1",""  ,
                ""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,""  ,
                "c0","m0","x0","s0","j0","s1","x1","m1","c1",
            ))
            return board
        }
    }
}