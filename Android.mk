LOCAL_PATH := $(call my-dir)
LIBRESETPROP_RUBY := $(LOCAL_PATH)/libresetprop_ruby

include $(CLEAR_VARS)

# general libresetprop_ruby variables
LOCAL_MODULE := libresetprop_ruby
LOCAL_MULTILIB := first
LOCAL_STATIC_LIBRARIES := libnanopb libmagisksystemproperties libmagiskutils
LOCAL_SHARED_LIBRARIES := liblog libselinux
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_RECOVERY_ROOT_OUT)/system/lib64
LOCAL_C_INCLUDES := \
    $(LIBRESETPROP_RUBY) \
    $(MAGISK_ROOT_PATH)/include \
    $(MAGISK_ROOT_PATH)/utils/include \
    $(LIBNANOPB) \
    $(LIBSYSTEMPROPERTIES) \
    $(LIBSYSTEMPROPERTIES)/include \
    $(LIBUTILS) \
    bionic/libc \
    bionic/libc/include \
    system/core/base/include \
    system/core/init

LOCAL_SRC_FILES := \
    $(LIBRESETPROP_RUBY)/persist.cpp \
    $(LIBRESETPROP_RUBY)/resetprop.cpp

LOCAL_CFLAGS += $(MAGISK_CFLAGS)
LOCAL_LDFLAGS := $(MAGISK_LDFLAGS)
LOCAL_CFLAGS += -Wno-implicit-fallthrough -std=c++17

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

# general ruby-detect-variant variables
LOCAL_MODULE := ruby-detect-variant
LOCAL_MODULE_CLASS := RECOVERY_EXECUTABLES
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_PATH := $(TARGET_RECOVERY_ROOT_OUT)/system/bin
LOCAL_SRC_FILES = \
    ruby-detect-variant.cpp \
    write-recovery-log.cpp \
    load-variant.cpp

LOCAL_CFLAGS = \
    -std=c++17 \
    -O3 \
    -Wall \
    -g

LOCAL_C_INCLUDES += \
    $(MAGISK_ROOT_PATH)/include \
    $(LOCAL_PATH)/include/detector \
    $(LOCAL_PATH)/include/resetprop \
    system/core/base/include \
    system/core/init

LOCAL_SHARED_LIBRARIES = \
    liblog \
    libresetprop_ruby \
    libselinux

LOCAL_STATIC_LIBRARIES = \
    libnanopb \
    libmagisksystemproperties \
    libmagiskutils

include $(BUILD_EXECUTABLE)
