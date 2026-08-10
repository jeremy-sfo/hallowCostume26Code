/*
====================================================
OLED Module

Displays the information about the costume (for now: used
for faces too)

DOESN'T handle logic
====================================================
*/

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 12, /* reset=*/ U8X8_PIN_NONE);

void setupOled(){

  u8g2.begin(); // start the oled
}

void updateOled(){
  u8g2.clearBuffer();                  // Clear the internal memory buffer
  u8g2.setFont(u8g2_font_courR08_tr);    // Choose a suitable scannable font

  u8g2.setCursor(0, 10);               // Set position to X=0, Y=15
  u8g2.print(millis());                // Natively prints numbers

  u8g2.setCursor(64, 10);               // Set position to X=0, Y=35
  u8g2.print(rawPotenValue);      

  //u8g2.drawXBMP(0, 113, 20, 20, batteryFullIconBar);    // battery icon
  drawCurrentFace(6, 16);     // update the face

u8g2.sendBuffer();                   // Push the buffer data to the screen
}