/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);  // set the LCD address to 0x27

void setup()
{
  lcd.begin (16,2); 
  lcd.print("Hello world!!"); 
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    lcd.clear();
    lcd.print(Serial.readString());
  }
}


