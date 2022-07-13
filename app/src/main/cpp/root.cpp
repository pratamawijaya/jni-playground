//
// Created by Pratama Nur Wijaya on 13/07/22.
//

#include "root.h"
#include <jni.h>
#include <string>
#include <time.h>
#include <sys/stat.h>
#include <stdio.h>
#include <android/log.h>
#include <errno.h>
#include <unistd.h>
#include <sys/system_properties.h>

using namespace std;

#define ANDROID_OS_BUILD_TAGS                "ro.build.tags"                     // Comma-separated tags describing the build, like "unsigned,debug".
#define TAG "NDK_LOG"
#define  ANDROID_LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE,    TAG, __VA_ARGS__)

extern "C" JNIEXPORT jboolean JNICALL
Java_com_pwijaya_jniplayground_ExternalRoot_rootCheck(JNIEnv *env, jobject instance) {
    //Access function checks whether a particular file can be accessed
    int result = access("/system/app/Superuser.apk", F_OK);

    ANDROID_LOGV("File Access Result superuser %d\n", result);

    int len;
    char build_tags[PROP_VALUE_MAX]; // PROP_VALUE_MAX from <sys/system_properties.h>.
    len = __system_property_get(ANDROID_OS_BUILD_TAGS,
                                build_tags); // On return, len will equal (int)strlen(model_id).
    if (strcmp(build_tags, "test-keys") == 0) {
        ANDROID_LOGV("Device has test keys %s\n", build_tags);
        result = 0;
    }
    ANDROID_LOGV("File Access Result %s\n", build_tags);
    if(result == 0){
        return true;
    }else {
        return false;
    }
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_pwijaya_jniplayground_ExternalRoot_rootCheck1(JNIEnv *env, jobject instance) {
    FILE *pipe = popen("which su", "r");

    if (!pipe) return -1;

    char buffer[128];
    std::string resultCmd = "";

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL)
            resultCmd += buffer;
    }
    pclose(pipe);

    const char *cstr = resultCmd.c_str();
    int result = -1;

    if (cstr == NULL || (strlen(cstr) == 0)) {
        ANDROID_LOGV("Result of Which command is Null");
    } else {
        result = 0;
        ANDROID_LOGV("Result of Which command %s\n", cstr);
    }
    if(result == 0) {
        return true;
    }else {
        return false;
    }
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_pwijaya_jniplayground_ExternalRoot_rootCheck2(JNIEnv *env, jobject instance) {
    int len;
    char build_tags[PROP_VALUE_MAX]; // PROP_VALUE_MAX from <sys/system_properties.h>.
    int result = -1;
    len = __system_property_get(ANDROID_OS_BUILD_TAGS, build_tags); // On return, len will equal (int)strlen(model_id).
    if(len >0 && strstr(build_tags,"test-keys") != NULL){
        ANDROID_LOGV( "Device has test keys\n", build_tags);
        result = 0;
    }
    if(result ==0){
        return true;
    }else {
        return false;
    }
}