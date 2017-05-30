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

void changePixel(int x, int y, int r, int g, int b) {
  displayArray[x][y][0] = r;
  displayArray[x][y][1] = g;
  displayArray[x][y][2] = b;
}

void drawWatson() {
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

  // Pause
  delay(5000);
}

void loop() {
  // Set some arbitrary values...
  drawWatson();
}
