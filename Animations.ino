void waitSumTime(unsigned long interval){

  unsigned long previousTime = millis();

  while (millis() - previousTime < interval){ // loop for the time of the interval

        if(userMadeInput) return; // if the user made an input immediately exit
        delay(1); // otherwise wait 1ms
    }
}

void characterBlinkingAnimation(){
/*
  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, getBlinkBitmap());
  u8g2.sendBuffer();

  waitSumTime(50);*/

  Serial.println("BLINK START");

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, getBlinkBitmap());
  u8g2.sendBuffer();

  delay(500);  // TEST ONLY

  Serial.println("BLINK END");
}

void characterLookAroundAnimation(){

}

void characterMoveMouthAnimation(){

}

void characterScreenSaverAnimation(){
  
}