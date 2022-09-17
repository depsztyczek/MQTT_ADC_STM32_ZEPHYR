# Introduction
This is a repository created to configure ADC and MQTT for water level measurement on Nucleo F429ZI with the use of Zephyr. It's starting point was the sample mqtt_publisher from zephyr repository. MQTT packets are sent with highest QoS (2) - they require ack.

## Setup environment for building and flashing the sample

## Configuring static IP wired connection on Ubuntu 20.04

1. Connect ethernet cable from STM32 to the ethernet port of the computer. 
2. Go to Settings > Network > Wired > Gears icon > IPv4 
3. Change IPv4 method to Manual
4. Under Addresses/Adress put 192.0.2.2 (or whatever IP address us written into prj.conf CONFIG_NET_CONFIG_PEER_IPV4_ADDR parameter)
5. Under Addresses/Netmask put 255.255.255.0
6. Gateway can be left empty

## Mosquitto test setup on Ubuntu 20.04

1. Download mosquitto.
2. Create a mosquitto.conf file, that contains the following:

```
listener 1883 0.0.0.0
allow_anonymous true
```
3. In one terminal call `mosquitto -v -c mosquitto.conf`
4. In another terminal call  `mosquitto_sub -t sensors`

