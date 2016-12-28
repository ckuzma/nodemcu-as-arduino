# AlexaWemoSwitch
![Photo of NodeMCU next to Amazon Dot](https://github.com/ckuzma/nodemcu-as-arduino/blob/develop/photos/alexawemo.jpg)
## Instructions
1. Download / clone this repo's code
2. Change the device name (by default it is "Christmas Lights")
3. Install [additional libraries](https://github.com/ckuzma/nodemcu-as-arduino#external-libraries) as needed and then flash the NodeMCU
4. Connect relay device to D1 (or whatever you selected) on the NodeMCU
5. Using another device, connect to the open ESP network to configure your wireless settings
6. Restart the NodeMCU (if necessary)
7. Scan for new Smart Home devices in the Alexa app
8. Say "Alexa, turn on the christmas lights" (or whatever you chose in step 2)

## Credit
This sketch began as a fork of Aruna Tennakoon's project using an Arduino D1 Mini as a WeMo switch, and then took on a bunch of modifications of its own. That original project can be found here: https://github.com/kakopappa/arduino-esp8266-alexa-wemo-switch
