/* ruby-detect-variant | recovery-logging.hpp */

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
