void characterBlinkingAnimation(){
  Serial.println("Animating");

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace1);
  waitSumTime(500);

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace2);
  waitSumTime(400);

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace3);
  waitSumTime(200);

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace4);
  waitSumTime(80);

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace1);
  waitSumTime(200);

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace2);
  waitSumTime(400);

  u8g2.drawXBMP(6, 16, 120, 50, blinkFace3);

  characterDoingAnimation = false;
}

void characterLookAroundAnimation(){

}

void characterMoveMouthAnimation(){

}

void characterScreenSaverAnimation(){
  
}