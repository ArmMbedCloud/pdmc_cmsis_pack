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

#ifndef MBED_CLOUD_CLIENT_USER_CONFIG_H
#define MBED_CLOUD_CLIENT_USER_CONFIG_H

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h>Connectivity Configuration
// ======================= 

//   <s.64> Wi-Fi SSID
//   <i> String-type value which can be provided for Wi-Fi access point.
//   <i> Default: SSID
#define SSID "SSID"

//   <s.64> Wi-Fi password
//   <i> String-type value which can be provided for Wi-Fi access point.
//   <i> Default: PASSWORD
#define PASSWORD "PASSWORD"

// </h>

// <h>PDMC Configuration
// ======================= 

//   <o.0>Trace log output
//      <0=> Disable
//      <1=> Enable
//   <i>Selects trace log output
//   <i>Disable, disable trace log output
//   <i>Enable, enable trace log output
#define MBED_CONF_MBED_TRACE_ENABLE 0

//   <s.64> Endpoint identification
//   <i> String-type value which can be provided for endpoint identification.
//   <i> Default: default
#ifndef MBED_CLOUD_CLIENT_ENDPOINT_TYPE
#define MBED_CLOUD_CLIENT_ENDPOINT_TYPE "default"
#endif

//   <o TRANSPORT_MODE>Transport mode
//      <1=> TCP
//      <2=> UDP
//      <3=> UDP QUEUE
//   <i>Selects transport mode
//   <i>TCP, typically for Ethernet and Wi-Fi devices.
//   <i>UDP, typically for Cellular and Mesh/Thread.
//   <i>It does not typically work unless your network connectivity stays open from the client to Pelion Device Management
//   <i>through all involved network elements. NATs and firewalls close UDP ports aggressively. Use either TCP or UDP_QUEUE.
//   <i>UDP QUEUE, use this for sleepy devices. 
//   <i>Sleepy devices are not reachable from Pelion Device Management immediately. 
//   <i>They are reachable when they have reconnected to Device Management.
//   <i>Device Management REST API operations, such as GET/PUT/POST, will be queued in Pelion Device Management, 
//   <i>until the device reconnects and the operations can be forwarded to it.
#define TRANSPORT_MODE 2

#if TRANSPORT_MODE == 1
#define MBED_CLOUD_CLIENT_TRANSPORT_MODE_TCP
#elif TRANSPORT_MODE == 2 
#define MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP
#elif TRANSPORT_MODE == 3
#define MBED_CLOUD_CLIENT_TRANSPORT_MODE_UDP_QUEUE
#else
#define MBED_CLOUD_CLIENT_TRANSPORT_MODE_TCP
#endif

//   <o>Endpoint lifetime [seconds] <60-259200>
//   <i> Expected lifetime of the registration of the LwM2M client in seconds.
//   <i> Minimum registration lifetime period is 60 seconds.
//   <i> Default: 3600 seconds
#ifndef MBED_CLOUD_CLIENT_LIFETIME
#define MBED_CLOUD_CLIENT_LIFETIME 86400
#endif

//   <o>CoAP blockwise size [bytes]<16=> 16 bytes <32=> 32 bytes
//                         <64=> 64 bytes <128=> 128 bytes
//                         <256=> 256 bytes <512=> 512 bytes
//                         <1024=> 1024 bytes
//   <i> Value for the maximum payload size to be sent and received at one blockwise message in bytes.
//   <i> Default: 512 bytes
#ifndef SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE
#define SN_COAP_MAX_BLOCKWISE_PAYLOAD_SIZE      1024
#endif

// Firmware update configuration
#define MBED_CLOUD_CLIENT_UPDATE_STORAGE ARM_UCP_FLASHIAP
#define MBED_CONF_MBED_CLOUD_CLIENT_UPDATE_DOWNLOAD_PROTOCOL MBED_CLOUD_CLIENT_UPDATE_DOWNLOAD_PROTOCOL_COAP
#define MBED_CONF_APP_MBED_CLOUD_CLIENT_UPDATE_BUFFER_SIZE 2048
#define MBED_CLOUD_CLIENT_UPDATE_BUFFER MBED_CONF_APP_MBED_CLOUD_CLIENT_UPDATE_BUFFER_SIZE

// B-L475E-IOT01A target specific configuration
#define COMPONENT_FLASHIAP 1
#define MBED_CONF_STORAGE_STORAGE_TYPE TDB_INTERNAL
#define MBED_CONF_UPDATE_CLIENT_STORAGE_ADDRESS 0x8088000
#define MBED_CONF_UPDATE_CLIENT_STORAGE_SIZE 0x78000
#define MBED_CONF_UPDATE_CLIENT_APPLICATION_DETAILS 0x8008000
#define MBED_CONF_MBED_CLOUD_CLIENT_DISABLE_CERTIFICATE_ENROLLMENT 1
#define BS_PATCH_COMPILE_TIME_MEMORY_ALLOC 1024
#define MBED_CONF_STORAGE_TDB_INTERNAL_INTERNAL_BASE_ADDRESS 0x8080000
#define MBED_CONF_STORAGE_TDB_INTERNAL_INTERNAL_SIZE 32768
#define FLASHIAP_APP_ROM_END_ADDR 0x8100000

//   <o.0>Provisioning mode
//      <0=> Production
//      <1=> Developer
//   <i>Selects provisioning mode
//   <i>Production, use FCU (Factory Configurator Utility)
//   <i>Developer, use developer certificate
#define MBED_CONF_APP_DEVELOPER_MODE 1

#define PAL_USE_HW_TRNG                 1
#define MBED_CLOUD_CLIENT_SUPPORT_UPDATE
#define UPDATE_CLIENT_STORAGE_FLASHIAP

//------------- <<< end of configuration section >>> ---------------------------

#endif // MBED_CLOUD_CLIENT_USER_CONFIG_H
