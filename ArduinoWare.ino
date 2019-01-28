#include "Keyboard.h"

#define VolUp 0xAF

void setup() {
  Keyboard.begin();
  pinMode(1, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(1) == LOW){
    for(int counter = 0; 0 < 100; counter++){
        Keyboard.press(VolUp);
        delay(100);
    }
    counter = 0;
    Keyboard.releaseAll();

    while(digitalRead(1) == LOW);
  }

  delay(100);
}
