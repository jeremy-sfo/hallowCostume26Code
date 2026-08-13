/*
====================================================
hallowCostume26
Version 0.2

Contains loop(), and setup() ONLY
====================================================
*/

#include <U8g2lib.h> // library for the OLED
#include <Arduino.h>
#include <Wire.h>
#include "Globals.h" // my own library

void setup(){

  Serial.begin(115200); // set the serial moniter baud

  setupButtons();
  setupPoten();
  setupOled();

  nextDelayTime = random(1800, 8000);
  animationTimer = millis();
}


void loop(){
  readButtons();
  readPoten();

  processingLoop();
  updateOled();

}