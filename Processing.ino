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
int blinkAnimationIndex = 5; // set it to neutral face blinking
unsigned long animationTimer = 0;


void processHeadPos(){ // take the raw poten value and assign it a enum state

  if(rawPotenValue < 215){
    currentHeadPosition = FULL_LEFT;
    blinkAnimationIndex = 6;
  }

  else if(rawPotenValue < 417){
    currentHeadPosition = SLIGHT_LEFT;
    blinkAnimationIndex = 7;
  }

  else if(rawPotenValue < 619){
    currentHeadPosition = NEUTRAL;
    blinkAnimationIndex = 5;
  } 

  else if(rawPotenValue < 821){
    currentHeadPosition = SLIGHT_RIGHT;
    blinkAnimationIndex = 9;
  }

  else{
    currentHeadPosition = FULL_RIGHT;
    blinkAnimationIndex = 8;
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
  if (randomAction < 44) characterBlinkingAnimation();

  else if (randomAction < 69) characterLookAroundAnimation();

  else if (randomAction < 89) characterMoveMouthAnimation();

  else characterScreenSaverAnimation();
}


void animateCharacter() {

  Serial.print("input=");
  Serial.print(userMadeInput);

  Serial.print(" animation=");
  Serial.print(characterDoingAnimation);

  Serial.print(" elapsed=");
  Serial.print(millis() - animationTimer);

  Serial.print(" target=");
  Serial.println(nextDelayTime);

  if (userMadeInput) return;

  if (!characterDoingAnimation) {

    if (millis() - animationTimer >= nextDelayTime) {

      Serial.println(">>> ANIMATION TRIGGERED <<<");

      characterDoingAnimation = true;

      characterBlinkingAnimation();

      characterDoingAnimation = false;

      animationTimer = millis();
      nextDelayTime = random(1800, 8000);
    }
  }
}

void processingLoop(){
  processHeadPos();
  animateCharacter();

  prevMillis = millis();
}

void waitSumTime(unsigned long interval){
  unsigned long previousTime = millis();

  while (millis() - previousTime < interval){ // loop for the time of the interval

        if(userMadeInput) return; // if the user made an input immediately exit
        delay(1); // otherwise wait 1ms
    }
}
