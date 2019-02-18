#include "HID-Project.h"
#define mituruButton 16

void setup() {
  pinMode(mituruButton, INPUT_PULLUP);
  Serial.print("Ready!");
  Consumer.begin();
}

void loop() {
  if (!digitalRead(mituruButton)) {
        for(int VolCount = 0; VolCount < 40 ; VolCount++){
          Consumer.write(MEDIA_VOLUME_UP);
          delay(10);
          Consumer.releaseAll();
          delay(10);
        }
        delay(1000);
  }
}
