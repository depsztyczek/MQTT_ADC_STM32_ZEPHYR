# Introduction
This is a repository created to configure ADC and MQTT for water level measurement on Nucleo F429ZI with the use of Zephyr. It's starting point was the sample mqtt_publisher from zephyr repository. MQTT packets are sent with highest QoS (2) - they require ack. Software configurations (for example turning off logging) can be done in prj.conf file, project related settings are in config.h file.

All of the below instructions were prepared for Ubuntu 20.04.

## Setup environment for building and flashing the sample
1. Setup ncs repository: https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/gs_installing.html
2. Clone this repo into ncs/zephyr/samples/
3. Open ncs/nrf/west.yml and add "hal_stm32" into name-allowlist section
4. Run `west update`

## Building and flashing the sample
1. Go into repo directory
2. `west build -b nucleo_f429zi`
3. `west flash -r jlink` (if the board uses ST-Link and not JLink, search for a suitable method or reflash the debugging interface to JLink: ( https://www.segger.com/products/debug-probes/j-link/models/other-j-links/st-link-on-board/ )

## Configuring static IP wired connection

1. Connect ethernet cable from STM32 to the ethernet port of the computer. 
2. Go to Settings > Network > Wired > Gears icon > IPv4 
3. Change IPv4 method to Manual
4. Under Addresses/Adress put 192.0.2.2 (or whatever IP address us written into prj.conf CONFIG_NET_CONFIG_PEER_IPV4_ADDR parameter)
5. Under Addresses/Netmask put 255.255.255.0
6. Gateway can be left empty

## Mosquitto test setup

1. Download mosquitto.
2. Create a mosquitto.conf file, that contains the following:

```
listener 1883 0.0.0.0
allow_anonymous true
```
3. In one terminal call `mosquitto -v -c mosquitto.conf`
4. In another terminal call  `mosquitto_sub -t sensors`

