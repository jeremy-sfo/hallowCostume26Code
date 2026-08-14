void waitSumTime(unsigned long interval){

  unsigned long previousTime = millis();

  while (millis() - previousTime < interval){ // loop for the time of the interval

        if(userMadeInput) return; // if the user made an input immediately exit
        delay(1); // otherwise wait 1ms
    }
}

void characterBlinkingAnimation(){
  //Serial.println(nextDelayTime);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, getBlinkBitmap());
  u8g2.sendBuffer();

  waitSumTime(2);
}

void characterLookAroundAnimation(){

}

void characterMoveMouthAnimation(){

}

void characterScreenSaverAnimation(){
  
}