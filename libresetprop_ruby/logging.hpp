#pragma once

#include <cerrno>
#include <cstdarg>
#include <android-base/logging.h>
#include "log.h"

struct log_callback {
    int (*d)(const char* fmt, va_list ap);
    int (*i)(const char* fmt, va_list ap);
    int (*w)(const char* fmt, va_list ap);
    int (*e)(const char* fmt, va_list ap);
    void (*ex)(int code);
};

extern log_callback log_cb;

#define LIBRESETPROP_RUBY "libresetprop_ruby"
#define WARN "W"
#define ERR  "E"
#define DEBG "D"
#define INF  "I"

android::base::InitLogging(nullptr, &android::base::StderrLogger);

#define LOGD(const char* fmt, ...) LOG(DEBUG) << LIBRESETPROP_RUBY << ": " << DEBG << ": " << fmt << " " << __VA_ARGS__
#define LOGE(const char* fmt, ...) LOG(ERROR) << LIBRESETPROP_RUBY << ": " << ERR << ": " << fmt << " " << __VA_ARGS__
#define LOGW(const char* fmt, ...) LOG(WARNING) << LIBRESETPROP_RUBY << ": " << WARN << ": " << fmt << " " << __VA_ARGS__
#define LOGI(const char* fmt, ...) LOG(INFO) << LIBRESETPROP_RUBY << ": " << INF << ": " << fmt << " " << __VA_ARGS__

int nop_log(const char *, va_list);
void nop_ex(int);

void no_logging();
void cmdline_logging();
