/* ruby-detect-variant | ruby-detect-variant.h */

#if !defined(__RUBY_DETECT_VARIANT__)
#define __RUBY_DETECT_VARIANT__

void write_recovery_log(char *logmessage, char *type);
void load_variant(char *target_variant, char *target_model);

#endif /* __RUBY_DETECT_VARIANT__ */

/* end */
