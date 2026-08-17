/*
====================================================
hallowCostume26 (Board: esp8266 nodeMCU 1.0)
Version 0.2

Stores all the global variables so you dont have to look 
for them. DOESN'T ACTUALLY GET RUN UNLESS YOU 
REFERENCE IT IN MAIN.INO

Contains definitions and pins of components, aswell as
important booleans
====================================================
*/

#pragma once // code guard so that if included twice there wont be overlapping variable

#include <Arduino.h>
#include <U8g2lib.h> // library for oled
#include <Wire.h>

/* ---------------- OLED ---------------- */

extern U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2; // define the oled

/* ---------------- Pins ---------------- */

const byte buttonPin = D5;
const byte potenPin = A0;

/* ---------------- VARIABLES ---------------- */

// ANTI-DEBOUNCE
extern long debounceDelay; 
extern unsigned long lastDebounceTime; // previouse debounce time [extern: declared but not defined here]

// POTENTIOMETER
extern int rawPotenValue; // value of the potentiometer (poten.ino)
extern int prevPotenValue; // stores the last ms' poten value

// DETECTION
extern boolean userMadeInput; // if the user inputted something
extern boolean characterDoingAnimation; // if there is currently an animation playing

// DIRECTION STATES
extern HeadOrientation currentFaceDirection; // the direction the user wants
extern HeadOrientation animationFaceDirection; // the direction the animation chooses

// DIRECTION DATA
extern const unsigned char* directionalBitmaps[];
extern SimulatedAxis currentAxis;

// EXPRESSION STATES
extern const unsigned char* expressionBitmaps[];
extern const RandomAnimation animationFaceDisplay;

// EXPRESSION DATA
extern int randomAction; // choose between 1-100 to simulate percents
extern BehaviorMode currentBehavior; // define a starting behavior 

// TIME
extern unsigned long nextDelayTime; // random animation delay time
extern unsigned long prevMillis;
extern unsigned long animationTimer; // timer to choose random animations

/* ---------- BITMAP DECLARATION --------- */
extern const unsigned char neutralFace[]; 
extern const unsigned char slightLeftFace[];
extern const unsigned char slightRightFace[];
extern const unsigned char fullLeftFace[];
extern const unsigned char fullRightFace[];

extern const unsigned char blinkFace1[];
extern const unsigned char blinkFace2[];
extern const unsigned char blinkFace3[];
extern const unsigned char blinkFace4[];

/* ---------------- ENUMS ---------------- */
enum SimulatedAxis{ // change axis to experience different faces
    YAW,
    PITCH
};  

enum HeadOrientation{ // define some basic four axis face positions (add later: diagonal face sensing)

  NEUTRAL,

  SLIGHT_LEFT,
  FULL_LEFT,

  SLIGHT_RIGHT,
  FULL_RIGHT,

  SLIGHT_UP,
  FULL_UP,

  SLIGHT_DOWN,
  FULL_DOWN
};

enum BehaviorMode{ // emotion sets for different faces

  NORMAL, 

  LOW_POWER,

  DETERMINED,

  HELPFUL
};

enum RandomAnimation{
  BLINK, 

  LOOK_AROUND,

  MOVE_MOUTH,

  SCREEN_SAVER
};

/* ------------ SETUP ------------- */
void setupButtons();
void setupPoten();
void setupOled();



/* ------------- LOOPS ------------- */
void readButtons();
void readPoten();
void updateOled();

void drawCurrentFace();
void processHeadPos();

/* ----------- PROCESSING ----------- */

void decideRandomAnimation();
void animateCharacter();

void characterBlinkingAnimation();
void characterLookAroundAnimation();
void characterMoveMouthAnimation();
void characterScreenSaverAnimation();

void waitSumTime();

const unsigned char* getBlinkBitmap();

