/* ruby-detect-variant | load-variant.c */

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

#define __VARIANT_LOADER_INCLUDED__
#define __IS_USES_LOGGING_FEATURES__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include <sys/system_properties.h>
#include <errno.h>
#include <ruby-detect-variant.h>
#include <logging-ruby.h>
#include <variants-ruby.h>

static void
setprop(char *property, char *value)
{
    if (__system_property_set(property, value) != 0)
    {
        /* I think it is right to include these types of errors only in android logs. */
        LOGERR("Failed to set property %s to %s. Reason: %s", property, value, strerror(errno));
        exit(45);
    }
}

void load_variant(char *target_variant, char *target_model)
{
    /* detect target variant */
    if (strcmp(target_variant, TARGET_1ND_DEVICE_NAME) == 0)
    {
        LOGINF("loading ruby variant...");
        write_recovery_log("loading ruby variant...", DETINF_INFO_TAG);
    } else if (strcmp(target_variant, TARGET_2ND_DEVICE_NAME) == 0)
    {
        LOGINF("loading rubypro variant...");
        write_recovery_log("loading rubypro variant...", DETINF_INFO_TAG);
    }

    /* apply properties */
    setprop("ro.product.name", target_variant);
    setprop("ro.build.product", target_variant);
    setprop("ro.vendor.product.device", target_variant);
    setprop("ro.vendor.product.device", target_variant);
    setprop("ro.system.product.device", target_variant);
    setprop("ro.system_ext.product.device", target_variant);
    setprop("ro.product.device", target_variant);
    setprop("ro.product.product.device", target_variant);
    setprop("ro.product.bootimage.device", target_variant);
    setprop("ro.product.odm.device", target_variant);
    setprop("ro.product.system.device", target_variant);
    setprop("ro.product.system_ext.device", target_variant);
    setprop("ro.product.vendor.device", target_variant);
    setprop("ro.product.board", target_variant);

    setprop("ro.product.model", target_model);
    setprop("ro.product.vendor.model", target_model);
    setprop("ro.product.odm.model", target_model);
    setprop("ro.product.system.model", target_model);
    setprop("ro.product.system_ext.model", target_model);
    setprop("ro.product.product.model", target_model);
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* end */
