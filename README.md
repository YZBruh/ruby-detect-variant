# TWRP variant detector binary for xiaomi ruby
It is licensed under Apache 2.0.

## How to build
I will explain step by step...

 - First download this repository and place it in the device tree in ruby-detect-variant folder name.
 - Add the following flag anywhere in `BoardConfig.mk` (after adding the `DEVICE_PATH` variable): `TARGET_RECOVERY_DEVICE_DIRS += $(DEVICE_PATH)/ruby-detect-variant`
 - And of course, add the following codes to the places you deem appropriate in `init.recovery.mt6877.rc`:

```
service ruby-detect-variant /vendor/bin/ruby-detect-variant
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
 - There are `ruby` and `rubypro` variants. The variant to be used currently is coded in `ruby/variants-ruby.h`. By editing the existing `DEFAULT_DEVICE` macro, you can thus select the variant to be loaded if a particular device cannot be detected. What's available now is `ruby`.

