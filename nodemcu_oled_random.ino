#include "SSD1306.h"

SSD1306  display(0x3c, D3, D4); // Specify pins display is connected to

int len = 128;
int ht = 64;
int board[128][64];

void drawBoard(int[128][64]);
void randomBoard();

void setup(){
  display.init();
  display.clear();
  display.setFont(ArialMT_Plain_10);
  display.drawString(40, 15, "Random");
  display.drawString(32, 30, "Visualization");
  display.display();
  delay(2000);
  display.clear();
}

void loop() {
  drawBoard(board);
  randomBoard();
  delay(10);
}

void drawBoard(int boardToDraw[128][64]){
  display.clear();
  for(int x=0; x<len; x++){
    for(int y=0; y<ht; y++){
      if(board[x][y] == 1){
        display.setPixel(x,y);
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

