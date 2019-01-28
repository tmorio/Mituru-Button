#include "HID-Project.h"
#define mituruButton 2

void setup() {
  pinMode(mituruButton, INPUT_PULLUP);
  Consumer.begin();
}

void loop() {
  if (!digitalRead(mituruButton)) {
    for(int counter = 0 ; 0 < 100 ; counter++){
      Consumer.write(MEDIA_VOLUME_UP);
      delay(10);
    }
  }
}
