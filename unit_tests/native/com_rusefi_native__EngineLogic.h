/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_rusefi_native__EngineLogic */

#ifndef _Included_com_rusefi_native__EngineLogic
#define _Included_com_rusefi_native__EngineLogic
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    getVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_rusefi_native_1_EngineLogic_getVersion
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    resetTest
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_resetTest
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    setSensor
 * Signature: (Ljava/lang/String;D)V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_setSensor
  (JNIEnv *, jobject, jstring, jdouble);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    getConfiguration
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_rusefi_native_1_EngineLogic_getConfiguration
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    setConfiguration
 * Signature: ([BII)V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_setConfiguration
  (JNIEnv *, jobject, jbyteArray, jint, jint);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    setEngineType
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_setEngineType
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    initTps
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_initTps
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    invokePeriodicCallback
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_invokePeriodicCallback
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    invokeEtbCycle
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_invokeEtbCycle
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    burnRequest
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_rusefi_native_1_EngineLogic_burnRequest
  (JNIEnv *, jobject);

/*
 * Class:     com_rusefi_native__EngineLogic
 * Method:    getOutputs
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_rusefi_native_1_EngineLogic_getOutputs
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
