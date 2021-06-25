package org.tty.musicplayer

import android.media.AudioManager
import android.media.MediaPlayer
import android.os.Handler
import android.os.Message
import android.widget.SeekBar
import androidx.appcompat.widget.AppCompatSeekBar
import androidx.appcompat.widget.AppCompatTextView
import java.lang.ref.WeakReference
class MusicPlayerHelper(val seekBar: AppCompatSeekBar, val text: AppCompatTextView) :MediaPlayer.OnBufferingUpdateListener, MediaPlayer.OnPreparedListener, MediaPlayer.OnCompletionListener  {
    private val mHandler: MusicPlayerHelperHandler = MusicPlayerHelperHandler(this)
    private val player: MediaPlayer = MediaPlayer()
    private lateinit var songModel: SongModel

    init {
        player.setAudioStreamType(AudioManager.STREAM_MUSIC)
        player.setOnBufferingUpdateListener(this)
        player.setOnPreparedListener(this)
        player.setOnCompletionListener(this)
    }

    override fun onBufferingUpdate(mp: MediaPlayer?, percent: Int) {

    }

    override fun onPrepared(mp: MediaPlayer?) {

    }

    override fun onCompletion(mp: MediaPlayer?) {

    }

    fun playBySongModel(songModel: SongModel, isResetPlayer: Boolean, url: String) {
        this.songModel = songModel
        if (isResetPlayer) {
            player.reset()
            player.setDataSource(url)
            player.prepareAsync()
        } else {
            player.start()
        }
    }

    fun pause() {
        if (player.isPlaying) {
            player.pause()
        }
    }

}

class MusicPlayerHelperHandler(helper: MusicPlayerHelper): Handler(){
    val helperRef: WeakReference<MusicPlayerHelper> = WeakReference(helper)

    override fun handleMessage(msg: Message) {
        super.handleMessage(msg)
    }
}