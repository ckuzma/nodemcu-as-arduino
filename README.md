# nodemcu_oled_sketches
Collection of Arduino sketches written for the NodeMCU and an OLED display. The display is connected via I2C on pins D3 and D4, but can be changed for your implementation. Uses the SSD1306 driver for ESP8266 found here: https://github.com/squix78/esp8266-oled-ssd1306

## OLED-based Sketches
### ConwaysGameOfLife
![Photo of conway sketch on NodeMCU](https://github.com/ckuzma/nodemcu_oled_sketches/blob/master/photos/conway.jpg)
The classic Conway's Game of Life played out on a tiny screen. Set to run 500 cycles per game (50 seconds per game) to avoid a stale board. Cells are set at 4x4 pixels each to keep memory overflows from occurring.

### RandomVizualizer
![Photo of random sketch on NodeMCU](https://github.com/ckuzma/nodemcu_oled_sketches/blob/master/photos/random.jpg)
Blocks are turned on and off randomly, each frame almost a sort-of QR code. It's a noisy visualization similar to an old TV without a signal.

### PlaneSpotter
Gives realtime information about airplanes traveling overhead by using the ADS-B Exchange API.

### WeatherStation
Displays weather information for a location using the Weather Underground API.

### WorldClock
Displays the time for cities around the world, along with a small image for a handful of locations.

## Credit
A lot of trailblazing work was done by people before me. I've left their names and licenses intact, and added my name to things that I've modified.
