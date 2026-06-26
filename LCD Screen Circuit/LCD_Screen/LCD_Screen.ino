/*
Simple LCD Circuit
Khaled Abdul-Baki
June 26, 2026


IMPORTANT: Make sure the LCD Screen is soldered to the I2C Bus extention to ensure stable connection

Connections (From -> TO):

Extention I2C Bus(VCC) -> Arduino(5V)
Extention I2C Bus(GND) -> Arduino(GND)
Extention I2C Bus(SDA) -> Arduino(SDA)
Extention I2C Bus(SCL) -> Arduino(SCL)

POTENTIOMETER:
Sometimes you may not see anything on the screen, make sure the potentiometer is at a suitable level

NOTICE:
Make sure to read the repository README.md Disclaimer before running or experimenting with this code!
*/





// LCD Libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initializing LCD 
LiquidCrystal_I2C lcd(0x27, 16, 2);

int i = 0;

void setup() {
  
  // 
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Moves the cursor to Col 0, and Row 0
  lcd.setCursor(0, 0);
  lcd.print("LCD super Tuff");
}

void loop() {

  // Moves cursor to Col 0, and Row 1
  lcd.setCursor(0, 1);
  lcd.print("Seconds: ");
  lcd.print(i);
  lcd.print("   "); 

  // Time goes up by one
  i++;

  // Waits one second
  delay(1000);
}