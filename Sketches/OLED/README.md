# NodeMCU + OLED
## Notes:
These sketches interface with an OLED screen (128x64 pixels) connected via I2C on pins D3 and D4 of the NodeMCU board. (Pins can be changed as desired.)

## General Instructions
*Install [additional libraries](https://github.com/ckuzma/nodemcu-as-arduino#external-libraries) as necessary*

1. Clone the repo and open up the desired sketch
2. Flash the NodeMCU firmware
3. Connect the display to pins D3 and D4 on the NodeMCU
4. Power on the NodeMCU
5. Using another device, connect to the open ESP network to configure your wireless settings
6. Restart the NodeMCU (if necessary) so that it connects to WiFi using the saved settings
7. If everything works as expected, modify the sketch with your details (eg. Latitude & longitude, UTC adjust, Weather Underground API key, block size, delay, etc.)
8. Flash the new code to your NodeMCU and enjoy

## Credit
`PlaneSpotter`, `WeatherStation`, and `WorldClock` are all forks of sketches written by Daniel Eichhorn. (He's also responsible for the excellent display driver I've made liberal use of.) I made modifications, such as removing the internal temperature sensor measurements, modifying time setting, etc. to fit my use cases. You can find the original project here: https://github.com/squix78/esp8266-weather-station
