
//#include <string.h>
#include <jni.h>
#include "org_purplei2p_i2pd_I2PD_JNI.h"
#include "DaemonAndroid.h"

JNIEXPORT jstring JNICALL Java_org_purplei2p_i2pd_I2PD_1JNI_getABICompiledWith
  (JNIEnv * env, jclass clazz) {
#if defined(__arm__)
  #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a/NEON (hard-float)"
      #else
        #define ABI "armeabi-v7a/NEON"
      #endif
    #else
      #if defined(__ARM_PCS_VFP)
        #define ABI "armeabi-v7a (hard-float)"
      #else
        #define ABI "armeabi-v7a"
      #endif
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
   #define ABI "x86"
#elif defined(__x86_64__)
   #define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
   #define ABI "mips64"
#elif defined(__mips__)
   #define ABI "mips"
#elif defined(__aarch64__)
   #define ABI "arm64-v8a"
#else
   #define ABI "unknown"
#endif

    return env->NewStringUTF(ABI);
}

JNIEXPORT jint JNICALL Java_org_purplei2p_i2pd_I2PD_1JNI_startDaemon
  (JNIEnv * env, jclass clazz) {
	return (jint)i2p::android::start();
}

JNIEXPORT void JNICALL Java_org_purplei2p_i2pd_I2PD_1JNI_stopDaemon
  (JNIEnv * env, jclass clazz) {
	i2p::android::stop();
}

