/* ruby-detect-variant | writelog.c */

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

#define __LOG_WRITER_INCLUDED__
#define __IS_USES_LOGGING_FEATURES__

#include <android/log.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <ruby-detect-variant.h>
#include <logging-ruby.h>
#include <recovery-logging-ruby.h>

void write_recovery_log(char *logmessage, char *type)
{
    static char recovery_logs_msg[1024];
    static char *logtype;
    FILE *reclogs;

    /* if recovery logs not found, exit */
    if (access(DETINF_RECOVERY_LOGS, F_OK) != 0)
    {
        LOGERR("no recovery logs were found. the target path: %s", DETINF_RECOVERY_LOGS);
        exit(9);
    }

    /* detect log tag */
    if (strcmp(type, DETINF_INFO_TAG) != 0) logtype = DETINF_INFO_TAG;
    else if (strcmp(type, DETINF_ERR_TAG) != 0) logtype = DETINF_ERR_TAG;
    else if (strcmp(type, DETINF_WARN_TAG) != 0) logtype = DETINF_WARN_TAG;
    else {
        LOGWARN("no matching tag was found (I, W or E). Currently, W is used. Please inform the developer.");
        logtype = DETINF_WARN_TAG;
    }

    /* generate recovery log message */
    sprintf(recovery_logs_msg, "%s:%s: %s", logtype, DETINF_LOG_TAG, logmessage);

    reclogs = fopen(DETINF_RECOVERY_LOGS, "a");
    /* open recovery log with write_only */
    if (reclogs == NULL)
    {
        LOGERR("Failed to open recovery logs!");
        exit(4);
    }

    /* write log */
    if (fprintf(reclogs, "%s", recovery_logs_msg) != 0)
    {
        fclose(reclogs);
        LOGERR("Failed to write recovery logs!");
        exit(3);
    }

    /* close recovery log */
    fclose(reclogs);
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* end */
