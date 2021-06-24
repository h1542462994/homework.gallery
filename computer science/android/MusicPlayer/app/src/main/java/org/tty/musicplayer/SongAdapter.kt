package org.tty.musicplayer

import android.annotation.SuppressLint
import android.content.Context
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.appcompat.widget.AppCompatImageView
import androidx.appcompat.widget.AppCompatTextView
import androidx.recyclerview.widget.RecyclerView


class SongAdapter(private val context: Context) : RecyclerView.Adapter<SongAdapter.SongViewHolder>()  {
    private val songs: ArrayList<SongModel> = arrayListOf()

    class SongViewHolder(view: View): RecyclerView.ViewHolder(view) {
        val image = view.findViewById<AppCompatImageView>(R.id.image_song)
        val text = view.findViewById<AppCompatTextView>(R.id.text_song)
    }

    @SuppressLint("NotifyDataSetChanged")
    fun setData(songs: List<SongModel>){
        this.songs.clear()
        this.songs.addAll(songs)
        this.notifyDataSetChanged()
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): SongViewHolder {
        val view = LayoutInflater.from(context).inflate(R.layout.card_music, parent, false)
        return SongViewHolder(view)
    }

    override fun onBindViewHolder(holder: SongViewHolder, position: Int) {
        val song = songs[position]
        when (song.isPlaying) {
            true -> {
                holder.image.setImageResource(R.drawable.ic_baseline_headset_24)
            }
            false -> {
                holder.image.setImageResource(R.drawable.ic_baseline_music_note_24)
            }
        }
        holder.text.text = song.name
    }

    override fun getItemCount(): Int {
        return songs.size
    }
}