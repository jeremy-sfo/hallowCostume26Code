/*
====================================================
Processing code

Handles all the logic, this is where we combine all the
information and tell the oled what to display
====================================================
*/

// define values from globals.h
SimulatedAxis currentAxis = YAW;
HeadOrientation currentHeadPosition = NEUTRAL; // define a starting head position
BehaviorMode currentBehavior = NORMAL; // define a starting behavior

boolean characterDoingAnimation = false;
unsigned long nextDelayTime = -1;
unsigned long prevMillis = millis();
int randomAction = -1;


void processHeadPos(){ // take the raw poten value and assign it a enum state

    if(rawPotenValue < 215){
        currentHeadPosition = FULL_LEFT;
    }
    else if(rawPotenValue < 417){
        currentHeadPosition = SLIGHT_LEFT;
    }
    else if(rawPotenValue < 619){
        currentHeadPosition = NEUTRAL;
    }
    else if(rawPotenValue < 821){
        currentHeadPosition = SLIGHT_RIGHT;
    }
    else{
        currentHeadPosition = FULL_RIGHT;
    }
}

void drawCurrentFace(int x, int y){

  switch(currentHeadPosition){ // loop through the head positions and decide which face to put on

    case NEUTRAL:
      u8g2.drawXBMP(x, y, 120, 50, neutralFace);
      break;

    case SLIGHT_LEFT:
      u8g2.drawXBMP(x, y, 120, 50, slightLeftFace);
      break;
    
    case FULL_LEFT:
      u8g2.drawXBMP(x, y, 120, 50, fullLeftFace);
      break;

    case SLIGHT_RIGHT:
      u8g2.drawXBMP(x, y, 120, 50, slightRightFace);
      break;
    
    case FULL_RIGHT:
      u8g2.drawXBMP(x, y, 120, 50, fullRightFace);
      break;
  }
}

void decideRandomAnimation(){
  switch(randomAction){

    case randomAction < 44:
      characterBlinkingAnimation();

    case randomAction < 69:
      characterLookAroundAnimation();

    case randomAction < 89:
      characterMoveMouthAnimation();

    case randomAction < 100:
      characterScreenSaverAnimation();

  } 

}


void animateCharacter(){
  if(userMadeInput) return; // exit the moment the user made an input

  if(!characterDoingAnimation){
    nextDelayTime = random(1800, 8000); // set a random delay time between 1.8 and 8 seconds
    characterDoingAnimation = true;

  } else{
    if(nextDelayTime == -1) return; // exit if the delay time has no value

    if(millis() - nextDelayTime > prevMillis && !userMadeInput){ // if enough time has passed and we aren't currently inputting
      randomAction = random(100); // find a random number between 0 and 99

      if(randomAction != -1) decideRandomAnimation(); //. play a random animation
    }
  }
}

void processingLoop(){
  processHeadPos();
  animateCharacter();

  prevMillis = millis();
}