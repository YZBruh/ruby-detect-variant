LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# module info
LOCAL_MODULE := ruby-detect-variant
LOCAL_MODULE_CLASS := RECOVERY_EXECUTABLES
LOCAL_MODULE_TAGS := optional

# install in to /system/bin
LOCAL_MODULE_PATH := $(TARGET_RECOVERY_ROOT_OUT)/system/bin

# compiler flags
LOCAL_CFLAGS = -O3 -Wall -g

# source
LOCAL_SRC_FILES = \
    ruby-detect-variant.c \
    write-recovery-log.c \
    load-variant.c

# headers
LOCAL_C_INCLUDES += $(LOCAL_PATH)/ruby

# link liblog
LOCAL_SHARED_LIBRARIES := liblog

include $(BUILD_EXECUTABLE)
