#include <jni.h>
#include <sys/types.h>

// You can remove functions you don't need

extern "C" {
#define EXPORT __attribute__((visibility("default"))) __attribute__((used))
EXPORT void nativeForkAndSpecializePre(
        JNIEnv *env, jclass clazz, jint *_uid, jint *gid, jintArray *gids, jint *runtimeFlags,
        jobjectArray *rlimits, jint *mountExternal, jstring *seInfo, jstring *niceName,
        jintArray *fdsToClose, jintArray *fdsToIgnore, jboolean *is_child_zygote,
        jstring *instructionSet, jstring *appDataDir, jboolean *isTopApp, jobjectArray *pkgDataInfoList,
        jobjectArray *whitelistedDataInfoList, jboolean *bindMountAppDataDirs, jboolean *bindMountAppStorageDirs) {
}

EXPORT int nativeForkAndSpecializePost(JNIEnv *env, jclass clazz, jint res) {
    if (res == 0) {
        InjectUserManager(env);
    } else {
        // in zygote process, res is child pid
        // don't print log here, see https://github.com/RikkaApps/Riru/blob/77adfd6a4a6a81bfd20569c910bc4854f2f84f5e/riru-core/jni/main/jni_native_method.cpp#L55-L66
    }
    return 0;
}

EXPORT __attribute__((visibility("default"))) void specializeAppProcessPre(
        JNIEnv *env, jclass clazz, jint *_uid, jint *gid, jintArray *gids, jint *runtimeFlags,
        jobjectArray *rlimits, jint *mountExternal, jstring *seInfo, jstring *niceName,
        jboolean *startChildZygote, jstring *instructionSet, jstring *appDataDir,
        jboolean *isTopApp, jobjectArray *pkgDataInfoList, jobjectArray *whitelistedDataInfoList,
        jboolean *bindMountAppDataDirs, jboolean *bindMountAppStorageDirs) {
    // added from Android 10, but disabled at least in Google Pixel devices
}

EXPORT __attribute__((visibility("default"))) int specializeAppProcessPost(
        JNIEnv *env, jclass clazz) {
    // added from Android 10, but disabled at least in Google Pixel devices
    return 0;
}

EXPORT void nativeForkSystemServerPre(
        JNIEnv *env, jclass clazz, uid_t *uid, gid_t *gid, jintArray *gids, jint *runtimeFlags,
        jobjectArray *rlimits, jlong *permittedCapabilities, jlong *effectiveCapabilities) {

}

EXPORT int nativeForkSystemServerPost(JNIEnv *env, jclass clazz, jint res) {
    if (res == 0) {
        // in system server process
    } else {
        // in zygote process, res is child pid
        // don't print log here, see https://github.com/RikkaApps/Riru/blob/77adfd6a4a6a81bfd20569c910bc4854f2f84f5e/riru-core/jni/main/jni_native_method.cpp#L55-L66
    }
    return 0;
}

EXPORT int shouldSkipUid(int uid) {
    // by default, Riru only call module functions in "normal app processes" (10000 <= uid % 100000 <= 19999)
    // false = don't skip
    return false;
}

EXPORT void onModuleLoaded() {
    // called when the shared library of Riru core is loaded
}
}

void InjectUserManager(JNIEnv *env) {
    if (env == nullptr) {
        LOGI("Failed to inject android.os.UserManager due to env is null")
        return;
    }
    LOGI("inject android.os.UserManager");

    jclass build_class = env->FindClass("android/os/UserManager");
    if (build_class == nullptr) {
        LOGW("failed to inject android.os.UserManager due to build is null");
        return;
    }

    jboolean in_work_profile = 0  // In JNI.h, 0 represents JNI_FALSE.
    jfieldID m_is_managed_profile_cached_id = env->GetStaticFieldID(build_class, "mIsManagedProfileCached", "Ljava/lang/Boolean;");

    if (m_is_managed_profile_cached_id != null) {
        env->SetBooleanField(build_class, m_is_managed_profile_cached_id, in_work_profile)
    }

    if (env->ExceptionCheck()) {
        env->ExceptionClear();
    }

    env->DeleteLocalRef(in_work_profile);
}