#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_hubert_saferoom_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Joooooachaim 98";
    return env->NewStringUTF(hello.c_str());
}
