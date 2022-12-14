/*
 * Copyright (c) 2017 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

// Network and MQTT configurations
#ifdef CONFIG_NET_CONFIG_SETTINGS
#define ZEPHYR_ADDR		        CONFIG_NET_CONFIG_MY_IPV4_ADDR
#define SERVER_ADDR		        CONFIG_NET_CONFIG_PEER_IPV4_ADDR
#endif

#define SERVER_PORT		        1883

#define APP_CONNECT_TIMEOUT_MS	2000
#define APP_SLEEP_MSECS		    500

#define APP_CONNECT_TRIES	    10

#define APP_MQTT_BUFFER_SIZE	128

#define MQTT_CLIENTID		    "zephyr_publisher"

// Threads configurations
#define STACK_SIZE              2048
#define ADC_PRIORITY            6
#define MQTT_PRIORITY           7

// ADC configurations
#define ADC_RESOLUTION		    12
#define ADC_GAIN		        ADC_GAIN_1
#define ADC_REFERENCE		    ADC_REF_INTERNAL
#define ADC_ACQUISITION_TIME	ADC_ACQ_TIME_DEFAULT
#define ADC_CHANNEL_NUMBER	    0

#define ACQ_TIME_INTERVAL_S     1

#endif
