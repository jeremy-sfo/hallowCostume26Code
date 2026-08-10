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

}


void loop(){
  readButtons();
  readPoten();

  processHeadPos();
  updateOled();

}