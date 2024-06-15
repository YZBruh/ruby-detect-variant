# TWRP variant detector binary for xiaomi ruby
It is licensed under Apache 2.0.

## How to build
I will explain step by step...

 - First download this repository and place it in the device tree in `ruby-detect-variant` folder name.
 - Then add the following flag in `device.mk`:
```make
PRODUCT_PACKAGES += \
    ruby-detect-variant \
    libresetprop_ruby
```
 - And of course, add the following codes to the places you deem appropriate in `init.recovery.mt6877.rc`:

```rc
service ruby-detect-variant /system/bin/ruby-detect-variant --default ruby
    user root
    group root
    disabled
    oneshot
    seclabel u:r:recovery:s0

on boot
    start ruby-detect-variant
```

## About the binary

 - This binary writes everything that happens to the android logs and recovery logs.
 - To change the current variant, simply change the available flag that you will add to the rc file (--default).
 - If the default variant flag is not used, ruby is used. If the wrong variant name is declared, an error is generated (and exit).
