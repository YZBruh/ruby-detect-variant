/* ruby-detect-variant | variants.h */

#if !defined(__VARIANTS__)
#define __VARIANTS__

/* variants */
#if defined(__VARIANT_LOADER_INCLUDED__) || defined(__RUBY_VARIANT_SET_INCLUDED__)
    #define TARGET_1ND_DEVICE_NAME    "ruby"
    #define TARGET_2ND_DEVICE_NAME    "rubypro"
    #define TARGET_1ND_DEVICE_MODEL   "22101316G"
    #define TARGET_2ND_DEVICE_MODEL   "22101316UCP"
#endif /* __VARIANT_LOADER_INCLUDED__ or __RUBY_VARIANT_SET_INCLUDED__ */

/* device information to be installed by default. you can change it. just rubypro or ruby */
#if defined(__RUBY_VARIANT_SET_INCLUDED__)
    #define DEFAULT_DEVICE   "ruby"
#endif /* __RUBY_VARIANT_SET_INCLUDED__ */

#endif /* __VARIANTS__ */

/* end */
