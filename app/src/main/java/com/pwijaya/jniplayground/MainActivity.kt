package com.pwijaya.jniplayground

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Button

class MainActivity : AppCompatActivity() {

    private val fnRoot by lazy { ExternalRoot() }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val button = findViewById<Button>(R.id.btnCheck)

        button.setOnClickListener {
            Log.d("debug", "root check -> ${fnRoot.rootCheck()}")
            Log.d("debug", "root check1 -> ${fnRoot.rootCheck1()}")
            Log.d("debug", "root check2 -> ${fnRoot.rootCheck2()}")

        }

    }
}