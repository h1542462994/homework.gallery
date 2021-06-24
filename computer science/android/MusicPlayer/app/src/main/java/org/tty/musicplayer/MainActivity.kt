package org.tty.musicplayer

import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.AppCompatButton
import androidx.appcompat.widget.AppCompatEditText
import androidx.lifecycle.MutableLiveData
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.google.gson.Gson
import com.google.gson.JsonObject
import kotlinx.coroutines.*
import okhttp3.OkHttpClient
import okhttp3.Request
import org.tty.musicplayer.net.ApiResponse
import org.tty.musicplayer.net.SongResult
import java.lang.Exception
import java.net.URI
import java.net.URLEncoder
import kotlin.concurrent.thread
import kotlin.coroutines.suspendCoroutine

class MainActivity : AppCompatActivity() {
    private lateinit var listSong: RecyclerView
    private lateinit var textSearch: AppCompatEditText
    private lateinit var buttonSearch: AppCompatButton
    private var songs: MutableLiveData<List<SongModel>> = MutableLiveData(listOf())
    private lateinit var listSongAdapter: SongAdapter
    private var searchText: MutableLiveData<String> = MutableLiveData()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        init()
    }

    private fun init() {
        listSong = findViewById(R.id.list_song)
        textSearch = findViewById(R.id.text_search)
        buttonSearch = findViewById(R.id.button_search)

        listSongAdapter = SongAdapter(this)
        listSong.adapter = listSongAdapter
        listSong.layoutManager = LinearLayoutManager(this)
        songs.value = listOf(SongModel("123456", "hello", isPlaying = false))

        textSearch.addTextChangedListener(object: TextWatcher {
            override fun beforeTextChanged(s: CharSequence?, start: Int, count: Int, after: Int) {

            }

            override fun onTextChanged(s: CharSequence?, start: Int, before: Int, count: Int) {

            }

            override fun afterTextChanged(s: Editable?) {
                searchText.value = s.toString()
            }
        })

        searchText.observeForever {
            Log.d(TAG, "searchText: ${searchText.value}")
        }

        songs.observeForever {
            listSongAdapter.setData(it)
        }

        buttonSearch.setOnClickListener { _ ->
            GlobalScope.launch {
                search()
            }
        }
    }

    suspend fun search() {
        return withContext(Dispatchers.IO) {
            try {
                thread {
                    val client = OkHttpClient()
                    val encodedSearchText =  URLEncoder.encode(searchText.value, "utf-8")
                    val request = Request.Builder()
                        .url("https://music.qier222.com/api/search?keywords=${encodedSearchText}&type=1&limit=16")
                        .build()
                    val response =  client.newCall(request).execute()
                    val responseData =  response.body().string()

                    val jsonObject = Gson().fromJson(responseData, JsonObject::class.java)
                    Log.d(TAG, jsonObject.toString())

                    val code = jsonObject.get("code").asInt
                    if (code == 200) {
                        val songResult = Gson().fromJson(jsonObject.get("result"), SongResult::class.java)
                        runOnUiThread {
                            songs.postValue(songResult.songs)
                        }
                    }
                }
            } catch (e: Exception) {
                e.printStackTrace()
            }
        }
    }

    companion object {
        private const val TAG = "MainActivity"

    }
}