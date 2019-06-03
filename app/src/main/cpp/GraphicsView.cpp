#include <jni.h>
#include <android/native_window_jni.h>
#include <android/log.h>
#include "cz/mg/vulkantest/Renderer.h"

using namespace cz::mg::vulkantest;

Renderer* renderer = nullptr;
ANativeWindow* window = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_cz_example_vulkantest_GraphicsView_onVulkanCreate(JNIEnv* env, jobject instance, jobject surface)
{
    __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s", "ON CREATE");
    window = ANativeWindow_fromSurface(env, surface);
    renderer = new Renderer(window);
}

extern "C"
JNIEXPORT void JNICALL
Java_cz_example_vulkantest_GraphicsView_onVulkanResize(JNIEnv* env, jobject instance, jobject surface, jint w, jint h)
{
    __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s %i %i", "ON RESIZE", w, h);
    renderer->resize(w, h);
}

extern "C"
JNIEXPORT void JNICALL
Java_cz_example_vulkantest_GraphicsView_onVulkanDestroy(JNIEnv* env, jobject instance, jobject surface)
{
    __android_log_print(ANDROID_LOG_DEBUG, "#####", "%s", "ON DESTROY");
    delete renderer;
    renderer = nullptr;
    ANativeWindow_release(window);
    window = nullptr;
}