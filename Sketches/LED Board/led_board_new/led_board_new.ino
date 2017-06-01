#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoMatrix.h>

#define LEFT_PIN D5
#define RIGHT_PIN D6

int displayArray[10][10][3] = {{0, 0, 0}};

Adafruit_NeoMatrix leftMatrix = Adafruit_NeoMatrix(
  5,
  10,
  LEFT_PIN,
  NEO_MATRIX_BOTTOM  + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);
Adafruit_NeoMatrix rightMatrix = Adafruit_NeoMatrix(
  5,
  10,
  RIGHT_PIN,
  NEO_MATRIX_TOP  + NEO_MATRIX_RIGHT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

void setup() {
  leftMatrix.begin();
  rightMatrix.begin();
  randomSeed(1989);
}

void changePixel(int x, int y, int r, int g, int b) {
  displayArray[x][y][0] = r;
  displayArray[x][y][1] = g;
  displayArray[x][y][2] = b;
}

void clearBoard() {
  for(int x = 0; x < 10; x++) {
    for(int y = 0; y < 10; y++) {
      changePixel(x, y, 0, 0, 0);
    }
  }
  displayBoard();
}

void displayBoard() {
  for(int x = 0; x < 10; x++){
    for(int y = 0; y < 10; y++) {
      int r = displayArray[x][y][0];
      int g = displayArray[x][y][1];
      int b = displayArray[x][y][2];
      if(x < 5) {
        leftMatrix.drawPixel(x, y, leftMatrix.Color(r, g, b));
      }
      else {
        rightMatrix.drawPixel(x-5, y, rightMatrix.Color(r, g, b));
      }
    }
  }
  leftMatrix.show();
  rightMatrix.show();
}



void drawSquares(int max_runs) {
  for(int count = 0; count < max_runs; count ++) {
    // Top left
  int r = random(80);
  int g = random(80);
  int b = random(80);
  for(int x = 0; x < 5; x++) {
    for(int y = 0; y < 5; y++) {
      changePixel(x, y, r, g, b);
    }
  }

  // Top right
  r = random(80);
  g = random(80);
  b = random(80);
  for(int x = 5; x < 10; x++) {
    for(int y = 0; y < 5; y++) {
      changePixel(x, y, r, g, b);
    }
  }


  // Bottom left
  r = random(80);
  g = random(80);
  b = random(80);
  for(int x = 0; x < 5; x++) {
    for(int y = 5; y < 10; y++) {
      changePixel(x, y, r, g, b);
    }
  }

  // Bottom right
  r = random(80);
  g = random(80);
  b = random(80);
  for(int x = 5; x < 10; x++) {
    for(int y = 5; y < 10; y++) {
      changePixel(x, y, r, g, b);
    }
  }

  // Display it
  displayBoard();
  delay(1000);
  }
}

void drawRandomColors(int max_runs) {
  for(int count = 0; count < max_runs; count ++) {
    for(int x = 0; x < 10; x++) {
      for(int y = 0; y < 10; y++) {
        changePixel(y, x, random(30), random(30), random(30));
        displayBoard();
        delay(50);
      }
    }
    delay(3000);
  }
}
void drawIBM() {
  for(int fadeNum = 0; fadeNum < 200; fadeNum ++){
    // I
    changePixel(0,0, 0, 0, fadeNum);
    changePixel(0,1, 0, 0, fadeNum);
    changePixel(0,2, 0, 0, fadeNum);
    changePixel(1,0, 0, 0, fadeNum);
    changePixel(1,1, 0, 0, fadeNum);
    changePixel(1,2, 0, 0, fadeNum);
    changePixel(2,0, 0, 0, fadeNum);
    changePixel(2,1, 0, 0, fadeNum);
    changePixel(2,2, 0, 0, fadeNum);
    changePixel(3,0, 0, 0, fadeNum);
    changePixel(3,1, 0, 0, fadeNum);
    changePixel(3,2, 0, 0, fadeNum);
    changePixel(4,0, 0, 0, fadeNum);
    changePixel(4,1, 0, 0, fadeNum);
    changePixel(4,2, 0, 0, fadeNum);
    changePixel(5,0, 0, 0, fadeNum);
    changePixel(5,1, 0, 0, fadeNum);
    changePixel(5,2, 0, 0, fadeNum);
    changePixel(6,0, 0, 0, fadeNum);
    changePixel(6,1, 0, 0, fadeNum);
    changePixel(6,2, 0, 0, fadeNum);
    changePixel(7,0, 0, 0, fadeNum);
    changePixel(7,1, 0, 0, fadeNum);
    changePixel(7,2, 0, 0, fadeNum);
    changePixel(8,0, 0, 0, fadeNum);
    changePixel(8,1, 0, 0, fadeNum);
    changePixel(8,2, 0, 0, fadeNum);
    changePixel(9,0, 0, 0, fadeNum);
    changePixel(9,1, 0, 0, fadeNum);
    changePixel(9,2, 0, 0, fadeNum);
    changePixel(3,3, 0, 0, fadeNum);
    changePixel(4,3, 0, 0, fadeNum);
    changePixel(5,3, 0, 0, fadeNum);
    changePixel(6,3, 0, 0, fadeNum);
    changePixel(3,4, 0, 0, fadeNum);
    changePixel(4,4, 0, 0, fadeNum);
    changePixel(5,4, 0, 0, fadeNum);
    changePixel(6,4, 0, 0, fadeNum);
    changePixel(3,5, 0, 0, fadeNum);
    changePixel(4,5, 0, 0, fadeNum);
    changePixel(5,5, 0, 0, fadeNum);
    changePixel(6,5, 0, 0, fadeNum);
    changePixel(3,6, 0, 0, fadeNum);
    changePixel(4,6, 0, 0, fadeNum);
    changePixel(5,6, 0, 0, fadeNum);
    changePixel(6,6, 0, 0, fadeNum);
    changePixel(0,7, 0, 0, fadeNum);
    changePixel(0,8, 0, 0, fadeNum);
    changePixel(0,9, 0, 0, fadeNum);
    changePixel(1,7, 0, 0, fadeNum);
    changePixel(1,8, 0, 0, fadeNum);
    changePixel(1,9, 0, 0, fadeNum);
    changePixel(2,7, 0, 0, fadeNum);
    changePixel(2,8, 0, 0, fadeNum);
    changePixel(2,9, 0, 0, fadeNum);
    changePixel(3,7, 0, 0, fadeNum);
    changePixel(3,8, 0, 0, fadeNum);
    changePixel(3,9, 0, 0, fadeNum);
    changePixel(4,7, 0, 0, fadeNum);
    changePixel(4,8, 0, 0, fadeNum);
    changePixel(4,9, 0, 0, fadeNum);
    changePixel(5,7, 0, 0, fadeNum);
    changePixel(5,8, 0, 0, fadeNum);
    changePixel(5,9, 0, 0, fadeNum);
    changePixel(6,7, 0, 0, fadeNum);
    changePixel(6,8, 0, 0, fadeNum);
    changePixel(6,9, 0, 0, fadeNum);
    changePixel(7,7, 0, 0, fadeNum);
    changePixel(7,8, 0, 0, fadeNum);
    changePixel(7,9, 0, 0, fadeNum);
    changePixel(8,7, 0, 0, fadeNum);
    changePixel(8,8, 0, 0, fadeNum);
    changePixel(8,9, 0, 0, fadeNum);
    changePixel(9,7, 0, 0, fadeNum);
    changePixel(9,8, 0, 0, fadeNum);
    changePixel(9,9, 0, 0, fadeNum);
    displayBoard();
    delay(10);
  }
  delay(1000);
  for(int fadeNum = 0; fadeNum < 200; fadeNum ++){
    // B
    for(int x = 0; x < 10; x++) {
      for(int y = 0; y < 10; y++) {
        changePixel(x, y, 0, 0, fadeNum);
      }
    }
    changePixel(8,0, 0, 0, 0);
    changePixel(9,0, 0, 0, 0);
    changePixel(9,4, 0, 0, 0);
    changePixel(9,5, 0, 0, 0);
    changePixel(9,9, 0, 0, 0);
    changePixel(2,2, 0, 0, 0);
    changePixel(3,2, 0, 0, 0);
    changePixel(4,2, 0, 0, 0);
    changePixel(5,2, 0, 0, 0);
    changePixel(6,2, 0, 0, 0);
    changePixel(2,3, 0, 0, 0);
    changePixel(3,3, 0, 0, 0);
    changePixel(4,3, 0, 0, 0);
    changePixel(5,3, 0, 0, 0);
    changePixel(2,6, 0, 0, 0);
    changePixel(3,6, 0, 0, 0);
    changePixel(4,6, 0, 0, 0);
    changePixel(5,6, 0, 0, 0);
    changePixel(6,6, 0, 0, 0);
    changePixel(7,6, 0, 0, 0);
    changePixel(2,7, 0, 0, 0);
    changePixel(3,7, 0, 0, 0);
    changePixel(4,7, 0, 0, 0);
    changePixel(5,7, 0, 0, 0);
    changePixel(6,7, 0, 0, 0);
    displayBoard();
    delay(10);
  }
  delay(1000);
  clearBoard();
  for(int fadeNum = 0; fadeNum < 200; fadeNum ++){
    // M
    for(int y = 0; y < 10; y++) {
      for(int x = 0; x < 3; x++) {
        changePixel(x, y, 0, 0, fadeNum);
      }
    }
    changePixel(3,2, 0, 0, fadeNum);
    changePixel(3,3, 0, 0, fadeNum);
    changePixel(3,4, 0, 0, fadeNum);
    changePixel(4,3, 0, 0, fadeNum);
    changePixel(4,4, 0, 0, fadeNum);
    changePixel(4,5, 0, 0, fadeNum);
    changePixel(5,3, 0, 0, fadeNum);
    changePixel(5,4, 0, 0, fadeNum);
    changePixel(5,5, 0, 0, fadeNum);
    changePixel(6,2, 0, 0, fadeNum);
    changePixel(6,3, 0, 0, fadeNum);
    changePixel(6,4, 0, 0, fadeNum);
    for(int y = 0; y < 10; y++) {
      for(int x = 7; x < 10; x++) {
        changePixel(x, y, 0, 0, fadeNum);
      }
    }
    displayBoard();
    delay(10);
  }
  delay(1000);
}

void drawWatson() {
  clearBoard();
  // Draw on
  changePixel(5, 0, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(2, 1, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(5, 1, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(8, 1, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(3, 2, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(5, 2, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(7, 2, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(0, 3, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(9, 3, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(1, 4, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(4, 4, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(5, 4, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(8, 4, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(3, 5, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(6, 5, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(2, 6, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(7, 6, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(2, 7, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(7, 7, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(3, 8, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(6, 8, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(4, 9, 31, 154, 236);
  displayBoard();
  delay(80);
  changePixel(5, 9, 31, 154, 236);
  displayBoard();
  delay(80);

  // Pause
  delay(5000);

  // Draw out
  changePixel(5, 0, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(2, 1, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(5, 1, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(8, 1, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(3, 2, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(5, 2, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(7, 2, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(0, 3, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(9, 3, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(1, 4, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(4, 4, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(5, 4, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(8, 4, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(3, 5, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(6, 5, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(2, 6, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(7, 6, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(2, 7, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(7, 7, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(3, 8, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(6, 8, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(4, 9, 0, 0, 0);
  displayBoard();
  delay(80);
  changePixel(5, 9, 0, 0, 0);
  displayBoard();
  delay(80);
}


void loop() {
  drawIBM();
  drawWatson();
  drawRandomColors(1);
  drawSquares(50);
}
