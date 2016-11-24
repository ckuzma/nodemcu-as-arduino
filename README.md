# nodemcu_oled_sketches
Collection of Arduino sketches written for the NodeMCU and an OLED display. The display is connected via I2C on pins D3 and D4, but can be changed for your implementation. Uses the SSD1306 driver for ESP8266 found here: https://github.com/squix78/esp8266-oled-ssd1306

## nodemcu_oled_conway
![Photo of conway sketch on NodeMCU](https://github.com/ckuzma/nodemcu_oled_sketches/blob/master/photos/conway.jpg)

The classic Conway's Game of Life played out on a tiny screen. Set to run 500 cycles per game (50 seconds per game) to avoid a stale board. Cells are set at 4x4 pixels each to keep memory overflows from occurring.


## nodemcu_oled_random
![Photo of random sketch on NodeMCU](https://github.com/ckuzma/nodemcu_oled_sketches/blob/master/photos/random.jpg)

Large cells are turned on and off randomly, creating a sort-of "living QR code" effect.
