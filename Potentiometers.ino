/*
====================================================
Buttons Module

Reads the  potentiometer(s), then turns that into a value from 0-1023 (esp8266's range)

Does NOT contain switching emotions logic.
====================================================
*/

// define stuff from globals.h
int rawPotenValue = 0; 
int prevPotenValue = 0;
boolean userMadeInput = false;


void setupPoten(){

  pinMode(potenPin, INPUT);
}

void readPoten(){
  rawPotenValue = analogRead(potenPin); // read the value of the knob

  // add dead zones at the end of the poten range to reduce jittering
  if(rawPotenValue <= 25) rawPotenValue = 0; 
  if(rawPotenValue >= 1000) rawPotenValue = 1023;

  if(abs(rawPotenValue - prevPotenValue > 5)) userMadeInput = true; // if the user probably touched the potentiometer

  else userMadeInput = false;

  prevPotenValue = rawPotenValue; // reset prev poten value
}


