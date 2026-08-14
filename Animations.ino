void characterBlinkingAnimation(){
  //Serial.println(nextDelayTime);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, blinkFace1);
  u8g2.sendBuffer();

 // waitSumTime(4);
}

void characterLookAroundAnimation(){

}

void characterMoveMouthAnimation(){

}

void characterScreenSaverAnimation(){
  
}