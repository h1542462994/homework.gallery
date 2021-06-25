package org.tty.musicplayer.net

class ApiResponse<T> where T: Any {
    var code: Int = 0
    lateinit var result: T
}