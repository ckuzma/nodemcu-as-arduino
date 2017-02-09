#include <Adafruit_NeoPixel.h>

#define PIN1 D5
#define PIN2 D6

int top[5][10][3];
int bottom[5][10][3];

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(50, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(50, PIN2, NEO_GRB + NEO_KHZ800);

void setup() {
  // Initialize the display, turn off
  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
  // Initialize the random seed
  randomSeed(1989);
}

void loop() {
  randomFill(false);
  displayBoard1();
  displayBoard2();
  delay(500); // 0.5 seconds
}

void randomFill(bool fill) {
  for(int x=0; x<5; x++){
    for(int y=0; y < 10; y++){
      for(int z=0; z<3; z++){
        if(fill == true){
          top[x][y][z] = random(3);
          bottom[x][y][z] = random(3);
        }
        else {
          top[x][y][z] = 0;
          bottom[x][y][z] = 0;
        }
      }
    }
  }
}

void displayBoard1() {
  for(int x=0; x<5; x++){
    for(int y=0; y < 10; y++){
      strip1.setPixelColor(x*10 + y, strip1.Color(top[x][y][0], top[x][y][1], top[x][y][2]));
    }
  }
  strip1.show();
}

void displayBoard2() {
  for(int x=0; x<5; x++){
    for(int y=0; y < 10; y++){
      strip2.setPixelColor(x*10 + y, strip2.Color(top[x][y][0], bottom[x][y][1], bottom[x][y][2]));
    }
  }
  strip2.show();
}


