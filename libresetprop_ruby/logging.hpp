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

#define LOGE(fmt, ...) \
  ((void)__android_log_print(ANDROID_LOG_ERROR, (LIBRESETPROP_RUBY), (fmt)__VA_OPT__(, ) __VA_ARGS__))
#define LOGW(fmt, ...) \
  ((void)__android_log_print(ANDROID_LOG_WARN, (LIBRESETPROP_RUBY), (fmt)__VA_OPT__(, ) __VA_ARGS__))
#define LOGI(fmt, ...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, (LIBRESETPROP_RUBY), (fmt)__VA_OPT__(, ) __VA_ARGS__))
#define LOGD(fmt, ...) \
  ((void)__android_log_print(ANDROID_LOG_DEBUG, (LIBRESETPROP_RUBY), (fmt)__VA_OPT__(, ) __VA_ARGS__))

__END_DECLS

int nop_log(const char *, va_list);
void nop_ex(int);

void no_logging();
void cmdline_logging();
