# nodemcu-as-arduino
Collection of Arduino sketches written for the NodeMCU. Many rely upon external libraries, the links for which can be found below.

## Amazon Alexa Interface Sketches
Sketches that enable the NodeMCU to be controlled by voice using an Alexa-powered device.

### AlexaWemoSwitch
![Photo of setup](https://github.com/ckuzma/nodemcu-as-arduino/blob/develop/photos/alexawemo.jpg)

Transforms the NodeMCU into a virtual WeMo UDP device that can be controlled by Alexa to turn on / off lights.

## OLED-based Sketches
These sketches interface with an OLED screen connected via I2C on pins D3 and D4 of the NodeMCU board. (Pins can be changed as desired.) Uses the SSD1306 driver below.

### ConwaysGameOfLife
![Photo of conway sketch on NodeMCU](https://github.com/ckuzma/nodemcu-as-arduino/blob/master/photos/conway.jpg)

The classic Conway's Game of Life played out on a tiny screen. Set to run 500 cycles per game (50 seconds per game) to avoid a stale board. Cells are set at 4x4 pixels each to keep memory overflows from occurring.

### RandomVizualizer
![Photo of random sketch on NodeMCU](https://github.com/ckuzma/nodemcu-as-arduino/blob/master/photos/random.jpg)

Blocks are turned on and off randomly, each frame almost a sort-of QR code. It's a noisy visualization similar to an old TV without a signal.

### PlaneSpotter
Gives realtime information about airplanes traveling overhead by using the ADS-B Exchange API.

### WeatherStation
Displays weather information for a location using the Weather Underground API.

### WorldClock
Displays the time for cities around the world, along with a small image for a handful of locations.

## External libraries:
A lot of my sketches wouldn't have possible without the work of others before me, and the great libraries they put together. Here's a quick reference guide to help find these necessary libraries.
* SSD1306.h, SSD1306Wire.h, OLEDDisplayUi.h - https://github.com/squix78/esp8266-oled-ssd1306
* JsonListener.h - https://github.com/squix78/json-streaming-parser
* AdsbExchangeClient.h, TimeClient.h, WundergroundClient.h - https://github.com/squix78/esp8266-weather-station
* WiFiManager.h - https://github.com/tzapu/WiFiManager
* ArduinoOTA.h, ESP8266WiFi.h, DNSServer.h, ESP8266WebServer.h, WiFiUdp.h - https://github.com/esp8266/Arduino
