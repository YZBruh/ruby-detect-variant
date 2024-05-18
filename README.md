# TWRP variant detector binary for xiaomi ruby
It is licensed under Apache 2.0.

## How to build
I will explain step by step...

 - First download this repository and place it in the device tree in any folder name.
 - Then add the following flag in device.mk somewhere under `PRODUCT_SOONG_NAMESPACES`: `PRODUCT_PACKAGES += ruby-detect-variant`
 - And of course, add the following codes to the places you deem appropriate in `init.recovery.mt6877.rc`:

```
service ruby-detect-variant /system/bin/ruby-detect-variant
    user root
    group root
    disabled
    oneshot
    seclabel u:r:recovery:s0

on boot
    start ruby-detect-variant
```
