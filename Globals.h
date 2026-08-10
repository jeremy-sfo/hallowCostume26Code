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

/* ---------------- Variables ---------------- */

// ANTI-DEBOUNCE
extern long debounceDelay; 
extern unsigned long lastDebounceTime; // previouse debounce time [extern: declared but not defined here]

// POTENTIOMETER
extern int rawPotenValue; // value of the potentiometer (poten.ino)

/* -------- Enums -------- */

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

extern SimulatedAxis currentAxis; // (main.ino)
extern HeadOrientation currentHeadPosition; // define a starting head position (main.ino)
extern BehaviorMode currentBehavior; // define a starting behavior (main.ino)

/* -------- Icons -------- */

// define all bitmaps here
extern const unsigned char batteryFullIconBar[]; 
extern const unsigned char neutralFace[]; 
extern const unsigned char slightLeftFace[];
extern const unsigned char slightRightFace[];
extern const unsigned char fullLeftFace[];
extern const unsigned char fullRightFace[];

extern int epdBitmapAllArrayLEN; // length of bitmap array
extern const unsigned char* epdBitmapAllArray[];



/* -------- Setup -------- */
void setupButtons();
void setupPoten();
void setupOled();



/* -------- Loops -------- */
void readButtons();
void readPoten();
void updateOled();

void drawCurrentFace();
void processHeadPos();

