# Basic setup steps
1. Install the Arduino IDE
2. Install the ESP8266 board libraries
3. Restart Arduino IDE
4. Plug in the board with a micro USB cable

# The longer version:
## Project Components
### Microcontroller
The LED board is powered by a [NodeMCU](http://nodemcu.com/index_en.html), which itself is a development board based on the [ESP8266](http://esp8266.net/) chip. It's essentially a SoC microcontroller that people have made a whole bunch of development boards out of. The advantages to working with it are built-in WiFi, a decent amount of GPIOs, a heck of a lot of processing power in a small package, and compatibility with the Arduino IDE and many of its libraries. While the NodeMCU isn't the cheapest ESP8266 board out there, it's both what I had experience working with at the time and also what I could spare to build something permanent.

### The LEDs
If I could do this part again I definitely would. I purchased a set of 100 SMD RGB LEDs (WS2812) which are individually addressable, enabling a single data pin to give instructions for a lot of LEDs wired in series. These are fully compatible with the easy-to-use [Adafruit NeoPixel](https://www.adafruit.com/category/168) library for Arduino, thus alleviating a lot of technical debt that I would have incurred trying to write my own driving code.

While the lights themselves work great, the process of manually soldering wires to and from each LED unit was tedious. Should I do this again I will probably opt to purchase strip-mounted LEDs with even spacing between them.

### The Layout
Once again, another area where I wish I had spent a bit more time and made better plans up front. The Adafruit libraries I am using actually have additional functionality that I am unable to use because of the layout of my LEDs. Instead I had to write a bit of custom driver code.

In short: my project requires two pins to drive the LEDs. Each pin is connected to half of the board's LEDs, with each of those strips connected to the adjacent row in a reversing zigzag pattern like so:
```
00 01 02 03 04 05 06 07 08 09
19 18 17 16 15 14 13 12 11 10
...
```

### Power
I added a simple barrel connector to the project so that I could utilize a power supply that offered the ability for all LEDs to be at full brightness without any flickering, while also ensuring that the NodeMCU board wouldn't reset itself. One doesn't need to have power connected to this in order to flash the NodeMCU with new firmware via USB. (And in most cases, USB power will suffice to run the board.)

### Installation and setup
First, install the Arduino IDE. Once done, follow [this guide to add](https://learn.sparkfun.com/tutorials/esp8266-thing-hookup-guide/installing-the-esp8266-arduino-addon) the ESP8266 libraries to the Arduino IDE. The site hosting the libraries occasionally goes down, which can be bypassed by going for the libraries found on GitHub. (ADD LINK HERE)

Stop following those instructions when you reach the section titled "Selecting the ESP8266 Thing Board". Instead of selecting the board mentioned in that step, select the one labeled "NodeMCU 1.0 (ESP-12E Module)" as that's what is found in the pixel board. Now when you plug in the pixel board, it should show up in the list of selectable ports for programmable devices.

You will also need to install the Adafruit NeoPixel libraries, which can be found at the above link.

### Programming the board
This part is more or less exactly like any other Arduino, except that the NodeMCU is a little bit slower to transfer firmware to. If it fails, unplug/re-plug the NodeMCU and try again, as it may have frozen up.