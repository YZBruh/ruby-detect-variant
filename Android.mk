# Copyright (C) 2024 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# module name
LOCAL_MODULE    := ruby-detect-variant

# source files
LOCAL_SRC_FILES := \
    ruby-detect-variant.c \
    write-recovery-log.c \
    load-variant.c

# compiler flags
LOCAL_CFLAGS := \
    -O3 \
    -g \
    -Wall \
    -Wexra

# libs to be linked
LOCAL_LDLIBS    := -llog

# other configs
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := EXECUTABLES

# install in to /system/bin
LOCAL_MODULE_PATH := $(TARGET_OUT_RECOVERY)/root/system/bin

include $(BUILD_EXECUTABLE)
