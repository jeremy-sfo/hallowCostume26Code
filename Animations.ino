void waitSumTime(unsigned long interval){

  unsigned long previousTime = millis();

  while (millis() - previousTime < interval){ // loop for the time of the interval

        if(userMadeInput) return; // if the user made an input immediately exit
        delay(1); // otherwise wait 1ms
    }
}

const unsigned char* getBlinkFace(){
  
  switch(currentHeadPosition){

    case NEUTRAL:
      return epd_bitmap_allArray[6];

    case FULL_LEFT:
      return epd_bitmap_allArray[6];

    case SLIGHT_LEFT:
      return epd_bitmap_allArray[7];

    case FULL_RIGHT:
      return epd_bitmap_allArray[8];

    case SLIGHT_RIGHT:
      return epd_bitmap_allArray[9];
  }

  return epd_bitmap_allArray[5]; // in case the above dont happen have smth just in case
}


void characterBlinkingAnimation(){
  //Serial.println(nextDelayTime);

  u8g2.clearBuffer();
  u8g2.drawXBMP(6, 16, 120, 50, getBlinkFace());
  u8g2.sendBuffer();

  waitSumTime(2);
}

void characterLookAroundAnimation(){

}

void characterMoveMouthAnimation(){

}

void characterScreenSaverAnimation(){
  
}