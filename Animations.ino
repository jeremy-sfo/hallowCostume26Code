void characterBlinkingAnimation(){
  Serial.println(nextDelayTime);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, blinkFace1);
  u8g2.sendBuffer(); 

  waitSumTime(10);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, blinkFace3);
  u8g2.sendBuffer();

  waitSumTime(8);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, blinkFace4);
  u8g2.sendBuffer(); 

  waitSumTime(5);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, blinkFace3);
  u8g2.sendBuffer(); 

  waitSumTime(5);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, blinkFace1);
  u8g2.sendBuffer(); 
  
  characterDoingAnimation = false;
}

void characterLookAroundAnimation(){

}

void characterMoveMouthAnimation(){

}

void characterScreenSaverAnimation(){
  
}