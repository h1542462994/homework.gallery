package org.tty.musicplayer.net

import org.tty.musicplayer.SongModel

class SongResult{
    var hasMore: Boolean = false
    var songCount: Int = 0
    var songs: List<SongModel> = listOf()
}