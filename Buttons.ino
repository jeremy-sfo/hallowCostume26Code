/*
====================================================
Buttons Module

Reads the  button(s).

Handles:
- Debounce
- Routing button presses

Does NOT contain switching emotions logic.
====================================================
*/

long debounceDelay = 50; // set for quick and snappy response
unsigned long lastDebounceTime = 0; // previouse debounce time 

void setupButtons(){

  pinMode(buttonPin, INPUT_PULLUP); // set the button as input with pull up
}

void readButtons(){
  int buttonState = digitalRead(buttonPin);

  
}