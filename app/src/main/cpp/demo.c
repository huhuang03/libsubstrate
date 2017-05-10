#include <jni.h>
#include "substrate.h"

/* This is a trivial JNI example where we use a native method
 * to return a new VM String. See the corresponding Java source
 * file located at:
 *
 */
JNIEXPORT jstring JNICALL
Java_common_com_libsubstrate_MainActivity_stringFromJNI(JNIEnv *env, jobject instance) {

    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI ");
}