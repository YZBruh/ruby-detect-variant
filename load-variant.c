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
#include <ruby-detect-variant.h>
#include <logging-ruby.h>
#include <variants-ruby.h>

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

    /* variables required to store terminal commands */
    static char productname[100];
    static char buildproduct[100];
    static char vendorproductdevice[100];
    static char systemproductdevice[100];
    static char system_extproductdevice[100];
    static char odmproductdevice[100];
    static char productdevice[100];
    static char productproductdevice[100];
    static char productbootimagedevice[100];
    static char productodmdevice[100];
    static char productsystemdevice[100];
    static char productsystem_extdevice[100];
    static char productvendordevice[100];
    static char productboard[100];

    static char productmodel[100];
    static char productvendormodel[100];
    static char productodmmodel[100];
    static char productsystemmodel[100];
    static char productsystem_extmodel[100];
    static char productproductmodel[100];

    /* generate terminal commands */
    sprintf(productname, "resetprop \"ro.product.name\" \"%s\"", target_variant);
    sprintf(buildproduct, "resetprop \"ro.build.product\" \"%s\"", target_variant);
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

    /* run commands */
    system(productname);
    system(buildproduct);
    system(vendorproductdevice);
    system(systemproductdevice);
    system(system_extproductdevice);
    system(odmproductdevice);
    system(productdevice);
    system(productproductdevice);
    system(productbootimagedevice);
    system(productodmdevice);
    system(productsystemdevice);
    system(productsystem_extdevice);
    system(productvendordevice);
    system(productboard);

    system(productmodel);
    system(productvendormodel);
    system(productodmmodel);
    system(productsystemmodel);
    system(productsystem_extmodel);
    system(productproductmodel);
}

/* end */
