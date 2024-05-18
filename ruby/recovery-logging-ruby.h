/* ruby-detect-variant | recovery-logging.h */

#pragma once

#if !defined(__RECOVERY_LOGGING__)
#define __RECOVERY_LOGGING__

/* recovery logging */
#if defined(__LOG_WRITER_INCLUDED__)
    /* recovery log path */
    #define DETINF_RECOVERY_LOGS    "/tmp/recovery.log"
#endif /* __LOG_WRITER_INCLUDED__ */

#endif /* __RECOVERY_LOGGING__ */

/* end */