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
Java_com_roger_facejni_FaceAction_Estimateaction(JNIEnv *env, jobject instance, jfloatArray landmarks) {
    jfloat * mrks = env->GetFloatArrayElements(landmarks,NULL);
    float * facelandmarks = mrks;

    string out ;
    out = faceact->estimateaction(facelandmarks);
    jstring result = (env)->NewStringUTF(out.data());
    return result;
}

JNIEXPORT jintArray JNICALL
Java_com_roger_facejni_FaceAction_EstimatePoseAngle(JNIEnv *env, jobject instance, jfloatArray landmarks) {
    jfloat * mrks = env->GetFloatArrayElements(landmarks,NULL);
    float * facelandmarks = mrks;

    int yaw_pitch_roll[3];
    faceact->estimateYawPitchRoll(facelandmarks, yaw_pitch_roll);

    int angles[] = {(int)round(yaw_pitch_roll[0]), (int)round(yaw_pitch_roll[1]), (int)round(yaw_pitch_roll[2])};
    jintArray yawpitchroll = env->NewIntArray(3);
    env->SetIntArrayRegion(yawpitchroll, 0, 3, angles);

    return yawpitchroll;
}

}