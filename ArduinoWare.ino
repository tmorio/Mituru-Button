#include "HID-Project.h"
#define mituruButton 2
#define proButton 3

bool ProtectButton = true;
int ButtonCounter = 0;

void setup() {
  pinMode(mituruButton, INPUT_PULLUP);
  Consumer.begin();
}

void loop() {
  //制限解除用ボタン
  if(!digitalRead(proButton) && ButtonCounter < 3){
    ButtonCounter++;
  }
  
  //解除用ボタンが3回押されたら制限モード解除
  if(ButtonCounter == 3){
    ProtectButton = false;
  }
  
  //メインボタンが押された時の動作
  if (!digitalRead(mituruButton)) {
    if(ProtectButton == false){
      for(int counter = 0 ; 0 < 100 ; counter++){
        Consumer.write(MEDIA_VOLUME_UP);  //制限モード解除時は音量を最大まで上げる
        delay(10);
      }
    }else{
        Consumer.write(MEDIA_VOLUME_UP);  //制限モード時は音量を1段階上げる
        delay(100);
    }
  }
}
