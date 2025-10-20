#include "hook.h"
#include "art_method_name.h"
#include "log_maker.h"

void
DealSetFieldValue(const string &tags, const string &type, const vector<Stack> &stack,
                  void(*hook)(JNIEnv *, jobject, jfieldID, jvalue v), JNIEnv *env, jobject obj,
                  jfieldID field, jvalue v) {
    Logs logs;
    logs.setStack(stack);
    logs.setJniEnv(env);
    logs.setName(tags);
    logs.setParams("jobject", obj);
    logs.setParams("jfieldID", field);
    logs.setParams(type, v);
    hook(env, obj, field, v);
    logs.log();
}

jobject
DealGetFieldValue(const string &tags, const string &type, const vector<Stack> &stack,
                  jobject(*hook)(JNIEnv *, jobject, jfieldID), JNIEnv *env, jobject obj,
                  jfieldID field) {
    Logs logs;
    logs.setStack(stack);
    logs.setJniEnv(env);
    logs.setName(tags);
    logs.setParams("jobject", obj);
    logs.setParams("jfieldID", field);
    auto result = hook(env, obj, field);
    logs.setResult(type, result);
    logs.log();
    return result;
}

#define DefineGetFieldHook(type, sigType) \
DefineHookStubCheckThreadPassJniTrace_Field(Get##type##Field, jobject, JNIEnv *,env, jobject, obj, jfieldID, field) { \
   return DealGetFieldValue("Get" #type "Field",sigType, _stack, pHook_Get##type##Field, env, obj, field);\
}

DefineGetFieldHook(Object, "L")

DefineGetFieldHook(Boolean, "Z")

DefineGetFieldHook(Byte, "B")

DefineGetFieldHook(Char, "C")

DefineGetFieldHook(Short, "S")

DefineGetFieldHook(Int, "I")

DefineGetFieldHook(Long, "J")

DefineGetFieldHook(Float, "F")

DefineGetFieldHook(Double, "D")

#define DefineSetFieldHook(type, sigType) \
DefineHookStubCheckThreadPassJniTrace_Field(Set##type##Field, void, JNIEnv*, env, jobject, obj, jfieldID, field, jvalue, v) { \
    DealSetFieldValue("Set" #type "Field",sigType, _stack, pHook_Set##type##Field, env, obj, field,v);\
}

DefineSetFieldHook(Object, "L")

DefineSetFieldHook(Boolean, "Z")

DefineSetFieldHook(Byte, "B")

DefineSetFieldHook(Char, "C")

DefineSetFieldHook(Short, "S")

DefineSetFieldHook(Int, "I")

DefineSetFieldHook(Long, "J")

DefineSetFieldHook(Float, "F")

DefineSetFieldHook(Double, "D")

void
DealSetStaticFieldValue(const string &tags, const string &type, const vector<Stack> &stack,
                        void(*hook)(JNIEnv *, jclass, jfieldID, jvalue v), JNIEnv *env, jclass clz,
                        jfieldID field, jvalue v) {
    Logs logs;
    logs.setStack(stack);
    logs.setJniEnv(env);
    logs.setName(tags);
    logs.setParams("jclass", clz);
    logs.setParams("jfieldID", field);
    logs.setParams(type, v);
    hook(env, clz, field, v);
    logs.log();
}

jobject
DealGetStaticFieldValue(const string &tags, const string &type, const vector<Stack> &stack,
                        jobject(*hook)(JNIEnv *, jclass, jfieldID), JNIEnv *env, jclass clz,
                        jfieldID field) {
    Logs logs;
    logs.setStack(stack);
    logs.setJniEnv(env);
    logs.setName(tags);
    logs.setParams("jclass", clz);
    logs.setParams("jfieldID", field);
    auto result = hook(env, clz, field);
    logs.setResult(type, result);
    logs.log();
    return result;
}

#define DefineSetStaticFieldHook(type, sigType) \
DefineHookStubCheckThreadPassJniTrace_Field(SetStatic##type##Field, void, JNIEnv*, env, jclass, clz, jfieldID, field, jvalue, v) { \
    DealSetStaticFieldValue("SetStatic" #type "Field",sigType, _stack, pHook_SetStatic##type##Field, env, clz, field,v);\
}

#define DefineGetStaticFieldHook(type, sigType) \
DefineHookStubCheckThreadPassJniTrace_Field(GetStatic##type##Field, jobject, JNIEnv *,env, jclass, clz, jfieldID, field) { \
   return DealGetStaticFieldValue("GetStatic" #type "Field",sigType, _stack, pHook_GetStatic##type##Field, env, clz, field);\
}


DefineSetStaticFieldHook(Object, "L")

DefineSetStaticFieldHook(Boolean, "Z")

DefineSetStaticFieldHook(Byte, "B")

DefineSetStaticFieldHook(Char, "C")

DefineSetStaticFieldHook(Short, "S")

DefineSetStaticFieldHook(Int, "I")

DefineSetStaticFieldHook(Long, "J")

DefineSetStaticFieldHook(Float, "F")

DefineSetStaticFieldHook(Double, "D")

DefineGetStaticFieldHook(Object, "L")

DefineGetStaticFieldHook(Boolean, "Z")

DefineGetStaticFieldHook(Byte, "B")

DefineGetStaticFieldHook(Char, "C")

DefineGetStaticFieldHook(Short, "S")

DefineGetStaticFieldHook(Int, "I")

DefineGetStaticFieldHook(Long, "J")

DefineGetStaticFieldHook(Float, "F")

DefineGetStaticFieldHook(Double, "D")