/* ruby-detect-variant | logging-shorts.h */

#pragma once

#if !defined(__LOGGING_RUBY__)
#define __LOGGING_RUBY__

#if defined(__IS_USES_LOGGING_FEATURES__) || defined(__LOG_WRITER_INCLUDED__)
    /* log targets */
    #define RECOVERY_LOG_TARGET  "recovery"
    #define ANDROID_LOG_TARGET   "logcat"

    /* log tags */
    #define DETINF_INFO_TAG      "I"
    #define DETINF_ERR_TAG       "E"
    #define DETINF_WARN_TAG      "W"
    #define DETINF_LOG_TAG       "ruby-detect-variant"

    /* logging */
    #define LOGINF(...) __android_log_print(ANDROID_LOG_INFO, DETINF_LOG_TAG, __VA_ARGS__)
    #define LOGERR(...) __android_log_print(ANDROID_LOG_ERROR, DETINF_LOG_TAG, __VA_ARGS__)
    #define LOGWARN(...) __android_log_print(ANDROID_LOG_WARN, DETINF_LOG_TAG, __VA_ARGS__)
#endif /* __IS_USES_LOGGING_FUNCS__ */

#endif /* __LOGGING_RUBY__ */

/* end */
