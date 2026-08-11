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

  if(prevPotenValue - rawPotenValue > 5 || rawPotenValue - prevPotenValue > 5){ // if the user probably touched the potentiometer
    userMadeInput = true;
  }

  prevPotenValue = rawPotenValue; // reset prev poten value
}


