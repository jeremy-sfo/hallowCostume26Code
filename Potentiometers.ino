/*
====================================================
Buttons Module

Reads the  potentiometer(s), then turns that into a value from 0-1023 (esp8266's range)

Does NOT contain switching emotions logic.
====================================================
*/

int rawPotenValue = 0; // define poten value from globals.h

void setupPoten(){

  pinMode(potenPin, INPUT);
}

void readPoten(){
  rawPotenValue = analogRead(potenPin); // read the value of the knob
}


