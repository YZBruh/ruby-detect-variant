/* ruby-detect-variant | ruby-set-variant.c */

/*
 * Copyright (C) 2024 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#define __RUBY_VARIANT_SET_INCLUDED__
#define __IS_USES_LOGGING_FEATURES__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include <ruby-detect-variant.h>
#include <logging-ruby.h>
#include <variants-ruby.h>

int main()
{
    /* write current status */
    LOGINF("starting variant loader...");
    write_recovery_log("starting variant loader...", DETINF_INFO_TAG);

    /* wait 2 second */
    sleep(2);

    LOGINF("detecting device...");
    write_recovery_log("detecting device...", DETINF_INFO_TAG);
    static char hwname[25];

    /* reset ro.boot.hwname property and get output */
    FILE *hw = popen("resetprop ro.boot.hwname", "r");

    /* check status */
    if (hw == NULL)
    {
        LOGERR("failed to reset ro.boot.hwname property");
        write_recovery_log("failed to reset ro.boot.hwname property", DETINF_ERR_TAG);
        exit(71);
    }

    /* detect variant */
    if (fgets(hwname, sizeof(hwname), hw) != NULL)
    {
        pclose(hw);
        /* load ruby variant */
        if (strcmp(hwname, TARGET_1ND_DEVICE_NAME) == 0)
        {
            LOGINF("ruby variant detected.");
            write_recovery_log("ruby variant detected.", DETINF_INFO_TAG);
            load_variant(TARGET_1ND_DEVICE_NAME, TARGET_1ND_DEVICE_MODEL);
        /* load rubypro variant */
        } else if (strcmp(hwname, TARGET_2ND_DEVICE_NAME) == 0)
        {
            LOGINF("rubypro variant detected.");
            write_recovery_log("rubypro variant detected.", DETINF_INFO_TAG);
            load_variant(TARGET_2ND_DEVICE_NAME, TARGET_2ND_DEVICE_MODEL);
        /* load default variant. please see loader.h */
        } else {
            LOGWARN("any device could not be detected. Using ruby variant.");
            write_recovery_log("any device could not be detected. Using default variant.", DETINF_WARN_TAG);
            load_variant(DEFAULT_DEVICE, TARGET_1ND_DEVICE_MODEL);
        }
    }

    exit(0);
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* end */
