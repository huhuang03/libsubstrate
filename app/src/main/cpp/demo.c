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

MSConfig(MSFilterExecutable, "/system/bin/app_process")

// this is a macro that uses __attribute__((__constructor__))
MSInitialize {
    // ... code to run when extension is loaded
}


static jint (*_Resources$getColor)(JNIEnv *jni, jobject _this, ...);

static jint $Resources$getColor(JNIEnv *jni, jobject _this, jint rid) {
    jint color = _Resources$getColor(jni, _this, rid);
    return color & ~0x0000ff00 | 0x00ff0000;
}

static void OnResources(JNIEnv *jni, jclass resources, void *data) {
    jmethodID method = (*jni)->GetMethodID(jni, resources, "getColor", "(I)I");
    if (method != NULL)
        MSJavaHookMethod(jni, resources, method,
                         &$Resources$getColor, &_Resources$getColor);
}

//MSJavaHookClassLoad(NULL, "android/content/res/Resources", &OnResources);
