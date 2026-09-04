/*
====================================================
Processing code

Handles all the logic, this is where we combine all the
information and tell the oled what to display
====================================================
*/

// define values from globals.h
SimulatedAxis currentAxis = YAW;
HeadOrientation currentFaceDirection = NEUTRAL;
HeadOrientation animationFaceDirection = NEUTRAL;
BehaviorMode currentBehavior = NORMAL; // define a starting behavior

boolean characterDoingAnimation = false;
unsigned long nextDelayTime = 0;
unsigned long prevMillis = millis();
int randomAction = 0;
unsigned long animationTimer = 0;

bool userMadeInput = false;

const unsigned char* animationFaceDisplay = neutralFace;

const int smallGravThreshold = 0.3;
const int largeGravThreshold = 0.6;


void processHeadPos(){ // // convert the MPU's reading into one of five head orientations.

  if(accelYg < -largeGravThreshold){ // full right
    currentFaceDirection = FULL_RIGHT;
    return;
  }

  if(accelYg < -smallGravThreshold){ // slight right
    currentFaceDirection = SLIGHT_RIGHT;
    return;
  }

  if(accelYg > smallGravThreshold){ // full right
    currentFaceDirection = SLIGHT_LEFT;
    return;
  }

  if(accelYg > largeGravThreshold){ // slight right
    currentFaceDirection = FULL_LEFT;
    return;
  }

  currentFaceDirection = NEUTRAL;
}

void decideRandomAnimation(){ // decide which random animation we will do

  if (randomAction < 44) characterBlinkingAnimation();

  else if (randomAction < 69) characterLookAroundAnimation();

  else if (randomAction < 89) characterMoveMouthAnimation();

  else characterScreenSaverAnimation();
}

void setAnimationFace(const unsigned char* face){ // function for setting the face of the animation
   animationFaceDisplay = face; 
} 

void drawCurrentFace(int x, int y){

  if(characterDoingAnimation){ // if we need to make animations use this

    u8g2.drawXBMP(x, y, 120, 50, animationFaceDisplay);
    return;
  }

  switch(currentFaceDirection){ // otherwise for normal faces use this

    case FULL_LEFT:
      u8g2.drawXBMP(x, y, 120, 50, fullLeftFace);
      break;

    case SLIGHT_LEFT:
      u8g2.drawXBMP(x, y, 120, 50, slightLeftFace);
      break;

    case NEUTRAL:
      u8g2.drawXBMP(x, y, 120, 50, neutralFace);
      break;

    case SLIGHT_RIGHT:
      u8g2.drawXBMP(x, y, 120, 50, slightRightFace);
      break;

    case FULL_RIGHT:
      u8g2.drawXBMP(x, y, 120, 50, fullRightFace);
      break;
  }
}

void animateCharacter() {

  /* FOR DEBUGGING ANIMATIONS
  
  Serial.print("input=");
  Serial.print(userMadeInput);

  Serial.print(" animation=");
  Serial.print(characterDoingAnimation);

  Serial.print(" elapsed=");
  Serial.print(millis() - animationTimer);

  Serial.print(" target=");
  Serial.println(nextDelayTime);*/

  if (userMadeInput) return;

  if (!characterDoingAnimation) {

    if (millis() - animationTimer >= nextDelayTime) {

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
