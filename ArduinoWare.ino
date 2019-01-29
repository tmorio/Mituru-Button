#include "HID-Project.h"
#define mituruButton 2
#define proButton 9

bool ProtectButton = true;
bool Changed = false;
int ButtonCounter = 0;

void setup() {
  pinMode(mituruButton, INPUT_PULLUP);
  pinMode(proButton, INPUT_PULLUP);
  Serial.print("Ready!");
  Consumer.begin();
}

void loop() {
  if(!digitalRead(proButton)){
    ButtonCounter++;
    delay(150);
  }

  if(ButtonCounter == 3 && Changed == false){
    ProtectButton = false;
    Changed = true;
    Serial.print("Changed Mode!");
  }
  
  if (!digitalRead(mituruButton)) {
    if(ProtectButton == false){
        for(int VolCount = 0; VolCount < 30 ; VolCount++){
          Consumer.write(MEDIA_VOLUME_UP);
          delay(10);
          Consumer.releaseAll();
          delay(10);
        }
        delay(1000);
    }else{
        Consumer.write(MEDIA_VOLUME_UP);
        delay(200);
        Consumer.releaseAll();
    }
  }
  Consumer.releaseAll();
}
