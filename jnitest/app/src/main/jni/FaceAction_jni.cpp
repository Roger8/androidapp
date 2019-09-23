//
// Created by Roger on 2019/9/23.
//

#include <android/log.h>
#include <jni.h>
#include <string>
#include <vector>

#include "FaceAction.h"

using namespace std;
#define TAG "FaceActionSo"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

static FaceAction* faceact;

extern "C" {

JNIEXPORT jboolean JNICALL
Java_com_roger_facejni_FaceAction_Helloworld(JNIEnv *env, jobject instance) {
    LOGD("hello jni;");
    faceact->Helloworld();
        return true;
   }

JNIEXPORT jstring JNICALL
Java_com_roger_facejni_FaceAction_Estimateaction(JNIEnv *env, jobject instance) {
    int mks[106*2];
    string out ;
    out = faceact->estimateaction(mks);
    jstring result = (env)->NewStringUTF("ok jni");
    return result;
}

}