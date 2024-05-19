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

#define __VARIANT_LOADER_INCLUDED__
#define __IS_USES_LOGGING_FEATURES__

#include <stdlib.h>
#include <unistd.h>
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
    static char *failsetpropmsg = NULL;
    if (__system_property_set(property, value) != 0)
    {
        LOGERR("Failed to set property %s to %s", property, value);
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

    sprintf(vendorproductdevice, "resetprop \"ro.vendor.product.device\" \"%s\"", target_variant);
    sprintf(systemproductdevice, "resetprop \"ro.system.product.device\" \"%s\"", target_variant);
    sprintf(system_extproductdevice, "resetprop \"ro.system_ext.product.device\" \"%s\"", target_variant);
    sprintf(productdevice, "resetprop \"ro.product.device\" \"%s\"", target_variant);
    sprintf(productproductdevice, "resetprop \"ro.product.product.device\" \"%s\"", target_variant);
    sprintf(productbootimagedevice, "resetprop \"ro.product.bootimage.device\" \"%s\"", target_variant);
    sprintf(productodmdevice, "resetprop \"ro.product.odm.device\" \"%s\"", target_variant);
    sprintf(productsystemdevice, "resetprop \"ro.product.system.device\" \"%s\"", target_variant);
    sprintf(productsystem_extdevice, "resetprop \"ro.product.system_ext.device\" \"%s\"", target_variant);
    sprintf(productvendordevice, "resetprop \"ro.product.vendor.device\" \"%s\"", target_variant);
    sprintf(productboard, "resetprop \"ro.product.board\" \"%s\"", target_variant);

    sprintf(productmodel, "resetprop \"ro.product.model\" \"%s\"", target_model);
    sprintf(productvendormodel, "resetprop \"ro.product.vendor.model\" \"%s\"", target_model);
    sprintf(productodmmodel, "resetprop \"ro.product.odm.model\" \"%s\"", target_model);
    sprintf(productsystemmodel, "resetprop \"ro.product.system.model\" \"%s\"", target_model);
    sprintf(productsystem_extmodel, "resetprop \"ro.product.system_ext.model\" \"%s\"", target_model);
    sprintf(productproductmodel, "resetprop \"ro.product.product.model\" \"%s\"", target_model);

}

/* end */
