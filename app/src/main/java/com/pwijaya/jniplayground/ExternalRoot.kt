package com.pwijaya.jniplayground

open class ExternalRoot {

    companion object {
        init {
            System.loadLibrary("root-lib");
        }
    }

    external fun rootCheck(): Boolean

    external fun rootCheck1(): Boolean

    external fun rootCheck2(): Boolean

}