#include "hook.h"
#include "art_method_name.h"
#include "log_maker.h"

#define IvkCallA(name, result, env, obj, method, jv)  \
    Logs logs;                                        \
    logs.setStack(_stack);                    \
    logs.setJniEnv(env);                              \
    logs.setName(#name);                              \
    logs.setCallParams(nullptr, obj, method, jv);     \
    result r = pHook_##name(env, obj, method, jv);    \
    logs.setCallResult((uint64_t)r);                      \
    logs.log();                                       \
    return r;

#define IvkCallAVoid(name, result, env, obj, method, jv)\
    Logs logs;                                          \
    logs.setStack(_stack);                        \
    logs.setJniEnv(env);                                \
    logs.setName(#name);                                \
    logs.setCallParams(nullptr, obj, method, jv);       \
    pHook_##name(env, obj, method, jv);                 \
    logs.log();

#define IvkCallAClz(name, result, env, obj, clz, method, jv)\
    Logs logs;                                              \
    logs.setStack(_stack);                            \
    logs.setJniEnv(env);                                    \
    logs.setName(#name);                                    \
    logs.setCallParams(clz, obj,  method, jv);              \
    result r = pHook_##name(env, obj,clz, method, jv);      \
    logs.setCallResult((uint64_t)r);                            \
    logs.log();                                             \
    return r;

#define IvkCallAClzVoid(name, result, env, obj, clz, method, jv) \
    Logs logs;                                                   \
    logs.setStack(_stack);                                 \
    logs.setJniEnv(env);                                         \
    logs.setName(#name);                                         \
    logs.setCallParams(clz, obj,  method, jv);                   \
    pHook_##name(env, obj,clz, method, jv);                      \
    logs.log();

#define IvkCall(name, result, env, obj, method)       \
    va_list ap;                                       \
    va_start(ap, method);                             \
    auto r = Hook_##name##V(env, obj, method,ap);    \
    va_end(ap);                                       \
    return r;

#define IvkCallVoid(name, result, env, obj, method) \
    va_list ap;                                     \
    va_start(ap, method);                           \
    Hook_##name##V(env, obj, method,ap);       \
    va_end(ap);

#define IvkCallClz(name, result, env, obj, clz, method)  \
    va_list ap;                                          \
    va_start(ap, method);                                \
    auto r = Hook_##name##V(env, obj,clz, method,ap);    \
    va_end(ap);                                          \
    return r;

#define IvkCallVoidClz(name, result, env, obj, clz, method) \
    va_list ap;                                             \
    va_start(ap, method);                                   \
    Hook_##name##V(env, obj,clz, method,ap);    \
    va_end(ap);

DefineHookStubCheckThreadPassJniTrace(CallObjectMethodA, jobject, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
               const jvalue *,jv) {
    IvkCallA(CallObjectMethodA, jobject, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallBooleanMethodA, jboolean, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
               const jvalue *,jv) {
    IvkCallA(CallBooleanMethodA, jboolean, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallByteMethodA, jbyte, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      const jvalue *, jv) {
IvkCallA(CallByteMethodA, jbyte, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallCharMethodA, jchar, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      const jvalue *, jv) {
IvkCallA(CallCharMethodA, jchar, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallShortMethodA, jshort, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      const jvalue *, jv) {
IvkCallA(CallShortMethodA, jshort, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallIntMethodA, jint, JNIEnv *, env, jobject, obj, jmethodID,
                                      method,
                                      const jvalue *, jv) {
IvkCallA(CallIntMethodA, jint, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallLongMethodA, jlong, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      const jvalue *, jv) {
IvkCallA(CallLongMethodA, jlong, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallFloatMethodA, jfloat, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      const jvalue *, jv) {
IvkCallA(CallFloatMethodA, jfloat, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallDoubleMethodA, jdouble, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      const jvalue *, jv) {
IvkCallA(CallDoubleMethodA, jdouble, env, obj, method, jv)
}

DefineHookStubCheckThreadPassJniTrace(CallVoidMethodA, void, JNIEnv *, env, jobject, obj, jmethodID,
                                      method, const jvalue *, jv)
{
IvkCallAVoid(CallVoidMethodA, void, env, obj, method, jv); }

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualObjectMethodA, jobject, JNIEnv *, env, jobject,
                                      obj, jclass, clz, jmethodID, method, const jvalue *, jv) {
    IvkCallAClz(CallNonvirtualObjectMethodA, jobject, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualBooleanMethodA, jboolean, JNIEnv *, env,
                                      jobject, obj, jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualBooleanMethodA, jboolean, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualByteMethodA, jbyte, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualByteMethodA, jbyte, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualCharMethodA, jchar, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualCharMethodA, jchar, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualShortMethodA, jshort, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualShortMethodA, jshort, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualIntMethodA, jint, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualIntMethodA, jint, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualLongMethodA, jlong, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualLongMethodA, jlong, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualFloatMethodA, jfloat, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualFloatMethodA, jfloat, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualDoubleMethodA, jdouble, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClz(CallNonvirtualDoubleMethodA, jdouble, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualVoidMethodA, void, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, const jvalue *,jv) {
    IvkCallAClzVoid(CallNonvirtualVoidMethodA, void, env, obj, clz, method, jv);
}

DefineHookStubCheckThreadPassJniTrace(CallObjectMethodV, jobject, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallObjectMethodV, jobject, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallBooleanMethodV, jboolean, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallBooleanMethodV, jboolean, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallByteMethodV, jbyte, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallByteMethodV, jbyte, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallCharMethodV, jchar, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallCharMethodV, jchar, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallShortMethodV, jshort, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallShortMethodV, jshort, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallIntMethodV, jint, JNIEnv *, env, jobject, obj, jmethodID,
                                      method,
                                      va_list, va) {
IvkCallA(CallIntMethodV, jint, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallLongMethodV, jlong, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallLongMethodV, jlong, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallFloatMethodV, jfloat, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallFloatMethodV, jfloat, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallDoubleMethodV, jdouble, JNIEnv *, env, jobject, obj,
                                      jmethodID, method,
                                      va_list, va) {
IvkCallA(CallDoubleMethodV, jdouble, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallVoidMethodV, void, JNIEnv *, env, jobject, obj, jmethodID,
                                      method,
                                      va_list, va) {
IvkCallAVoid(CallVoidMethodV, void, env, obj, method, va); }

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualObjectMethodV, jobject, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualObjectMethodV, jobject, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualBooleanMethodV, jboolean, JNIEnv *, env,
                                      jobject, obj, jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualBooleanMethodV, jboolean, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualByteMethodV, jbyte, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualByteMethodV, jbyte, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualCharMethodV, jchar, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualCharMethodV, jchar, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualShortMethodV, jshort, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualShortMethodV, jshort, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualIntMethodV, jint, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualIntMethodV, jint, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualLongMethodV, jlong, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualLongMethodV, jlong, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualFloatMethodV, jfloat, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualFloatMethodV, jfloat, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualDoubleMethodV, jdouble, JNIEnv *, env, jobject,
                                      obj, jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClz(CallNonvirtualDoubleMethodV, jdouble, env, obj, clz, method, va);
}

DefineHookStubCheckThreadPassJniTrace(CallNonvirtualVoidMethodV, void, JNIEnv *, env, jobject, obj,
                                      jclass, clz,
               jmethodID, method, va_list ,va) {
    IvkCallAClzVoid(CallNonvirtualVoidMethodV, void, env, obj, clz, method, va);
}

DefineHookStub(CallObjectMethod, jobject, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallObjectMethod, jobject, env, obj, method);
}

DefineHookStub(CallBooleanMethod, jboolean, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallBooleanMethod, jboolean, env, obj, method);
}

DefineHookStub(CallByteMethod, jbyte, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallByteMethod, jbyte, env, obj, method);
}

DefineHookStub(CallCharMethod, jchar, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallCharMethod, jchar, env, obj, method);
}

DefineHookStub(CallShortMethod, jshort, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallShortMethod, jshort, env, obj, method);
}

DefineHookStub(CallIntMethod, jint, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallIntMethod, jint, env, obj, method);
}

DefineHookStub(CallLongMethod, jlong, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallLongMethod, jlong, env, obj, method);
}

DefineHookStub(CallFloatMethod, jfloat, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallFloatMethod, jfloat, env, obj, method);
}

DefineHookStub(CallDoubleMethod, jdouble, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCall(CallDoubleMethod, jdouble, env, obj, method);
}

DefineHookStub(CallVoidMethod, void, JNIEnv *env, jobject obj, jmethodID method, ...) {
    IvkCallVoid(CallVoidMethod, void, env, obj, method);
}

DefineHookStub(CallNonvirtualObjectMethod, jobject, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualObjectMethod, jobject, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualBooleanMethod, jboolean, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualBooleanMethod, jboolean, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualByteMethod, jbyte, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualByteMethod, jbyte, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualCharMethod, jchar, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualCharMethod, jchar, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualShortMethod, jshort, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualShortMethod, jshort, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualIntMethod, jint, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualIntMethod, jint, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualLongMethod, jlong, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualLongMethod, jlong, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualFloatMethod, jfloat, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualFloatMethod, jfloat, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualDoubleMethod, jdouble, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallClz(CallNonvirtualDoubleMethod, jdouble, env, obj, clz, method);
}

DefineHookStub(CallNonvirtualVoidMethod, void, JNIEnv *env, jobject obj, jclass clz,
               jmethodID method, ...) {
    IvkCallVoidClz(CallNonvirtualVoidMethod, void, env, obj, clz, method);
}


#define IvkCallStaticAClz(name, env, clz, method, jv)\
    Logs logs;                                              \
    logs.setStack(_stack);                            \
    logs.setJniEnv(env);                                    \
    logs.setName(#name);                                    \
    logs.setCallParams(clz, nullptr,  method, jv);              \
    auto r = pHook_##name(env, clz, method, jv);      \
    logs.setCallResult((uint64_t)r);                        \
    logs.log();                                             \
    return r;
//                     ScopedObjectAccessAlreadyRunnable soa, jobject obj, jmethodID mid,
#define IvkCallStaticAClzVoid(name, env, clz, method, jv) \
    Logs logs;                                                   \
    logs.setStack(_stack);                                 \
    logs.setJniEnv(env);                                         \
    logs.setName(#name);                                         \
    logs.setCallParams(clz, nullptr,  method, jv);                   \
    pHook_##name(env, clz, method, jv);                      \
    logs.log();
//                     va_list args) {
//    if (passCallMethod) {
#define IvkCallStaticClz(name, env, clz, method)  \
    va_list ap;                                       \
    va_start(ap, method);                             \
    auto r = Hook_##name##V(env, clz, method,ap);    \
    va_end(ap);                                       \
    return r;
////        logi("pass dealCallMethodVaList");
#define IvkCallStaticVoidClz(name, env, clz, method) \
    va_list ap;                                       \
    va_start(ap, method);                             \
    Hook_##name##V(env, clz, method,ap);              \
    va_end(ap);
//        return hook(soa, obj, mid, args);
DefineHookStubCheckThreadPassJniTrace(CallStaticObjectMethodV, jobject, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticObjectMethodV, env, clz, method, va)
}
//    if (!jniTrace.CheckTargetModule(stack) || passJniTrace) {
DefineHookStubCheckThreadPassJniTrace(CallStaticBooleanMethodV, jboolean, JNIEnv *, env, jclass,
                                      clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticBooleanMethodV, env, clz, method, va)
}
//    passJniTrace = true;
DefineHookStubCheckThreadPassJniTrace(CallStaticByteMethodV, jbyte, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticByteMethodV, env, clz, method, va)
}
//    try {
DefineHookStubCheckThreadPassJniTrace(CallStaticCharMethodV, jchar, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticCharMethodV, env, clz, method, va)
//        JNIEnv *env = *(JNIEnv **) ((uint64_t) soa + sizeof(void *));
}
//        string method_pretty_name = jniHelper.GetMethodName(mid,
DefineHookStubCheckThreadPassJniTrace(CallStaticShortMethodV, jshort, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticShortMethodV, env, clz, method, va)
}
//        vector<string> args_type;
DefineHookStubCheckThreadPassJniTrace(CallStaticIntMethodV, jint, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticIntMethodV, env, clz, method, va)
//            throw "parse_java_method_sig error!";
}
//        string logs = tag + " call java: " + method_pretty_name + "\n";
DefineHookStubCheckThreadPassJniTrace(CallStaticLongMethodV, jlong, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticLongMethodV, env, clz, method, va)
}
//        va_list va_cpy;
DefineHookStubCheckThreadPassJniTrace(CallStaticFloatMethodV, jfloat, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticFloatMethodV, env, clz, method, va)
}
//        for (int i = 0; i < args_type.size(); ++i) {
DefineHookStubCheckThreadPassJniTrace(CallStaticDoubleMethodV, jdouble, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClz(CallStaticDoubleMethodV, env, clz, method, va)
}
//        auto result = hook(soa, obj, mid, args);
DefineHookStubCheckThreadPassJniTrace(CallStaticObjectMethodA, jobject, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticObjectMethodA, env, clz, method, jv)
}
//        jvalue realObject;
DefineHookStubCheckThreadPassJniTrace(CallStaticBooleanMethodA, jboolean, JNIEnv *, env, jclass,
                                      clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticBooleanMethodA, env, clz, method, jv)
//            realObject = result;
//        }
}
//        string resultStr = SerializeJavaObject(env, ret_type, realObject);
DefineHookStubCheckThreadPassJniTrace(CallStaticByteMethodA, jbyte, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticByteMethodA, env, clz, method, jv)
}
//        if (decode) {
DefineHookStubCheckThreadPassJniTrace(CallStaticCharMethodA, jchar, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticCharMethodA, env, clz, method, jv)
}
//        string stackStr;
DefineHookStubCheckThreadPassJniTrace(CallStaticShortMethodA, jshort, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticShortMethodA, env, clz, method, jv)
}
//        logs += xbyl::format_string("\t\t\t\t\tat: %s\n", stackStr.c_str());
DefineHookStubCheckThreadPassJniTrace(CallStaticIntMethodA, jint, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticIntMethodA, env, clz, method, jv)
}
////        if (argsSerialize.size() == 2 && argsSerialize[1] == "1920") {
DefineHookStubCheckThreadPassJniTrace(CallStaticLongMethodA, jlong, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticLongMethodA, env, clz, method, jv)
////            unwinder.Init();
////            unwinder.Unwind(&frame_info, 6);
////            for (const auto &item: frame_info) {
////                unwinderStr += xbyl::format_string("%p,", item.rel_pc);
////            }
////            logi("unwinder %d - %s", unwinderStr.size(), unwinderStr.c_str());
////            logs += xbyl::format_string("\t\t\t\t\tat: %s\n", unwinderStr.c_str());
////        }
}
//        log2file("%s", logs.c_str());
DefineHookStubCheckThreadPassJniTrace(CallStaticFloatMethodA, jfloat, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticFloatMethodA, env, clz, method, jv)
}
//}
DefineHookStubCheckThreadPassJniTrace(CallStaticDoubleMethodA, jdouble, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClz(CallStaticDoubleMethodA, env, clz, method, jv)
}
////_ZN3art35InvokeVirtualOrInterfaceWithVarArgsERKNS_33ScopedObjectAccessAlreadyRunnableEP8_jobjectP10_jmethodIDSt9__va_list
DefineHookStubCheckThreadPassJniTrace(CallStaticVoidMethodA, void, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, const jvalue *, jv) {
IvkCallStaticAClzVoid(CallStaticVoidMethodA, env, clz, method, jv)
//               ScopedObjectAccessAlreadyRunnable soa, jobject obj, jmethodID mid, va_list args) {
}
//    return dealCallMethodVaList("InvokeVirtualOrInterfaceWithVarArgs", GetStack01(),
DefineHookStubCheckThreadPassJniTrace(CallStaticVoidMethodV, void, JNIEnv *, env, jclass, clz,
                                      jmethodID, method, va_list, va) {
IvkCallStaticAClzVoid(CallStaticVoidMethodV, env, clz, method, va)
//                                pHook_InvokeVirtualOrInterfaceWithVarArgs, soa, obj, mid, args);
}
//
DefineHookStub(CallStaticObjectMethod, jobject, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticObjectMethod, env, clz, method); }
//DefineHookStub(InvokeWithVarArgs, jvalue,
DefineHookStub(CallStaticBooleanMethod, jboolean, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticBooleanMethod, env, clz, method); }
//               ScopedObjectAccessAlreadyRunnable soa, jobject obj, jmethodID mid, va_list args) {
DefineHookStub(CallStaticByteMethod, jbyte, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticByteMethod, env, clz, method); }
//    return dealCallMethodVaList("InvokeWithVarArgs", GetStack01(),
DefineHookStub(CallStaticCharMethod, jchar, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticCharMethod, env, clz, method); }
//                                pHook_InvokeWithVarArgs, soa, obj, mid, args);
DefineHookStub(CallStaticShortMethod, jshort, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticShortMethod, env, clz, method); }
//}
DefineHookStub(CallStaticIntMethod, jint, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticIntMethod, env, clz, method); }
//    va_start(ap, mid);
DefineHookStub(CallStaticLongMethod, jlong, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticLongMethod, env, clz, method); }
//    }
DefineHookStub(CallStaticFloatMethod, jfloat, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticFloatMethod, env, clz, method); }
//    va_end(ap);
DefineHookStub(CallStaticDoubleMethod, jdouble, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticClz(CallStaticDoubleMethod, env, clz, method); }
//    return local_result;
DefineHookStub(CallStaticVoidMethod, void, JNIEnv *env, jclass clz, jmethodID method,
               ...) { IvkCallStaticVoidClz(CallStaticVoidMethod, env, clz, method); }
//}
