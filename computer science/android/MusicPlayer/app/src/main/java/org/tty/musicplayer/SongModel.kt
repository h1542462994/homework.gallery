package org.tty.musicplayer

data class SongModel(
    val id: String,
    val name: String,
    var isPlaying: Boolean = false
)