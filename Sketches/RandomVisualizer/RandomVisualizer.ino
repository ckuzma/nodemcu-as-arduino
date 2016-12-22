/********************************************************************************
* MIT License                                                                   *
*                                                                               *
* Copyright (c) 2016 Christopher Kuzma                                          *
*                                                                               *
* Permission is hereby granted, free of charge, to any person obtaining a copy  *
* of this software and associated documentation files (the "Software"), to deal *
* in the Software without restriction, including without limitation the rights  *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell     *
* copies of the Software, and to permit persons to whom the Software is         *
* furnished to do so, subject to the following conditions:                      *
*                                                                               *
* The above copyright notice and this permission notice shall be included in all*
* copies or substantial portions of the Software.                               *
*                                                                               *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,      *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE   *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER        *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE *
* SOFTWARE.                                                                     *
********************************************************************************/

#include "SSD1306.h"

// Set where to find the board
SSD1306  display(0x3c, D3, D4); // Specify pins display is connected to, might have to change address

// Set display stuff
const int len = 8; // 128 native pixels / 4 pixels per cell = 32 virtual cells length
const int ht = 4; // 64 native pixels / 4 pixels per cell = 16 virtual cells height
const int pixelSize = 16; // Set how many native pixels = pixels per cell length or width
const bool flipScreen = false; // If you need to flip the screen

// Initialize the board
int board[len][ht];

// Function prototypes
void drawBoard();
void randomBoard();

void setup(){
  // Init the display
  display.init();
  if(flipScreen == true){
    display.flipScreenVertically();
  }

  // Display the title
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.drawString(40, 15, "Random");
  display.drawString(32, 30, "Visualization");
  display.display();
  delay(2000);
  display.clear();
}

void loop() {
  drawBoard();
  randomBoard();
  delay(100);
}

void drawBoard(){
  display.clear();
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      if(board[x][y] == 1){
//        display.setPixel(x,y);
          display.fillRect(x*pixelSize, y*pixelSize, pixelSize, pixelSize);
      }
    }
  }
  display.display();
}

void randomBoard(){
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      board[x][y] = random(0,2);
    }
  }
}

