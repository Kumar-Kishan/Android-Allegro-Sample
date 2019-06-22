package me.kishankumar.allegro

import org.liballeg.android.AllegroActivity

class MainActivity : AllegroActivity("libnative-lib.so") {
    companion object {
        init {
            System.loadLibrary("allegro")
            System.loadLibrary("allegro_primitives")
            System.loadLibrary("allegro_image")
            System.loadLibrary("allegro_font")
            System.loadLibrary("allegro_ttf")
            System.loadLibrary("allegro_audio")
            System.loadLibrary("allegro_acodec")
            System.loadLibrary("allegro_color")
        }
    }
}