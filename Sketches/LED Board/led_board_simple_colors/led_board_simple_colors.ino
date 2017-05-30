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

  // Initialize the random seed
  randomSeed(1989);
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

void makePrettyColors() {
  int prettyColors[3][3] = {
    {10, 0, 0},
    {0, 10, 10},
    {5, 10, 0}
  };
  for(int x = 0; x < 10; x++) {
    for(int y = 0; y < 10; y++) {
      int colorNumber = random(3);
      changePixel(x, y, prettyColors[colorNumber][0], prettyColors[colorNumber][1],prettyColors[colorNumber][2]);
    }
  }
}

void loop() {
  // Simple animation
  makePrettyColors();

  // Display it!
  displayBoard();

  delay(800);
}
