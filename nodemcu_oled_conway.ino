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
const int len = 32; // 128 native pixels / 4 pixels per cell = 32 virtual cells length
const int ht = 16; // 64 native pixels / 4 pixels per cell = 16 virtual cells height
const int pixelSize = 4; // Set how many native pixels = pixels per cell length or width
const bool flipScreen = false; // If you need to flip the screen


// Counter and seed value
int seedValue = 0;
int counter = 0;
int maxCycles = 500; // 500 cycles per game * 0.1 sec per cycle = 50 second games

// Initialize the board
int board[len][ht];
int newBoard[len][ht];

// Function prototypes
int countNeighbors(int, int);
void drawBoard();
void randomBoard();

// Runs when powering on
void setup(){
  // Init the display
  display.init();
  if(flipScreen == true){
    display.flipScreenVertically();
  }

  // Display the title
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.drawString(40, 15, F("Conway\'s"));
  display.drawString(32, 30, F("Game of Life"));
  display.drawString(0, 51, "Starting game " + String(seedValue + 1) + "...");
  display.display();
  delay(2000);
  display.clear();

  // Seed the board
  randomBoard();
}

// Main loop
void loop() {
  // Catch for number of cycles per game
  if(counter == maxCycles){
    randomSeed(seedValue);
    randomBoard();
    seedValue++;
    counter = 0;
    display.clear();
    display.drawString(0, 51, "Starting game " + String(seedValue + 1) + "...");
    display.display();
    delay(2000);
    display.clear();
  }

  // Draw the board, increment cycle counter
  drawBoard();
  makeNewBoard();
  counter++;

  // Do a 0.1 second delay
  delay(100);
}

void drawBoard(){
  display.clear();
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      if(board[x][y] == 1){
        display.fillRect(x*pixelSize, y*pixelSize, pixelSize, pixelSize);
      }
    }
  }
  display.display();
}

int countNeighbors(int x, int y){
  return board[x-1][y]+board[x-1][y-1]+board[x][y-1]+board[x+1][y-1]+board[x+1][y]+board[x+1][y+1]+board[x][y+1]+board[x-1][y+1];
}

void makeNewBoard(){
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      int neighbors = countNeighbors(x, y);
      if(board[x][y] == 1 && (neighbors == 2 || neighbors == 3)){
        newBoard[x][y] = 1;
      }
      else if(board[x][y] == 1){
        newBoard[x][y] = 0;
      }
      if(board[x][y] == 0 && (neighbors == 3)){
        newBoard[x][y] = 1;
      }
      else if (board[x][y] == 0){
        newBoard[x][y] = 0;
      }
    }
  }
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      board[x][y] = newBoard[x][y];
    }
  }
}

void randomBoard(){
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      board[x][y] = random(0,2);
    }
  }
}

