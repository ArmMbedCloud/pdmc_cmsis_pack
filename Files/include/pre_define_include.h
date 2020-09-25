// ----------------------------------------------------------------------------
// Copyright 2018-2020 ARM Ltd.
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------

#ifndef PRE_DEFINE_INCLUDE_H
#define PRE_DEFINE_INCLUDE_H

// Config files
#define PAL_USER_DEFINED_CONFIGURATION "mbed_cloud_client_user_config.h"
#define MBED_CLOUD_CLIENT_USER_CONFIG_FILE "mbed_cloud_client_user_config.h"
#define MBED_CLIENT_USER_CONFIG_FILE "mbed_cloud_client_user_config.h"
#define NS_EVENTLOOP_USER_CONFIG_FILE "mbed_cloud_client_user_config.h"
#define MBEDTLS_CONFIG_FILE "mbedtls_config_RTX.h"

#include PAL_USER_DEFINED_CONFIGURATION

#define MBED_CONF_NS_HAL_PAL_EVENT_LOOP_THREAD_STACK_SIZE 8192
#define MBED_CONF_MBED_CLOUD_CLIENT_EXTERNAL_SST_SUPPORT 1
#define PAL_USE_FILESYSTEM 0
#define ATOMIC_QUEUE_USE_PAL 1
#define ARM_UC_FEATURE_DELTA_PAAL 0
#define ARM_UC_PROFILE_MBED_CLOUD_CLIENT 1

#define MBED_CLOUD_APPLICATION_NONSTANDARD_ENTRYPOINT

// Do not modify below ones!
#define NS_EVENTLOOP_USE_TICK_TIMER     1
#define NS_EXCLUDE_HIGHRES_TIMER        1

/* Developer flags for Update feature */
#if defined(MBED_CONF_APP_DEVELOPER_MODE) &&  (MBED_CONF_APP_DEVELOPER_MODE == 1)
    #define MBED_CLOUD_DEV_UPDATE_CERT
    #define MBED_CLOUD_DEV_UPDATE_ID
#endif /* MBED_CONF_APP_DEVELOPER_MODE */

#define MBED_CONF_NANOSTACK_EVENTLOOP_EXCLUDE_HIGHRES_TIMER
#define MBED_CONF_NANOSTACK_EVENTLOOP_USE_PLATFORM_TICK_TIMER

#endif
