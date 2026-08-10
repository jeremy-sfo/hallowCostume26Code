/*
====================================================
Processing code

Handles all the logic, this is where we combine all the
information and tell the oled what to display
====================================================
*/

// define enum values from globals.h
SimulatedAxis currentAxis = YAW;
HeadOrientation currentHeadPosition = NEUTRAL; // define a starting head position
BehaviorMode currentBehavior = NORMAL; // define a starting behavior

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

//void updateFace(){
//}