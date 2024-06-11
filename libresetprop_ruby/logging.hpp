#pragma once

#include <cerrno>
#include <cstdarg>
#include <sys/cdefs.h>
#include <android/log.h>

extern log_callback log_cb;

#define LIBRESETPROP_RUBY "libresetprop_ruby"

/**
 * from system/logging/liblog/include/android/log_macros.h
 * warning: edited
 */

__BEGIN_DECLS

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LIBRESETPROP_RUBY, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LIBRESETPROP_RUBY, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LIBRESETPROP_RUBY, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LIBRESETPROP_RUBY, __VA_ARGS__)

__END_DECLS

int nop_log(const char *, va_list);
void nop_ex(int);

void no_logging();
void cmdline_logging();
