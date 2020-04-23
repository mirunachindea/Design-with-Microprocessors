#include <LiquidCrystal.h>
// include I2C library
#include <Wire.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int x = 0;
void setup() {
  // Open I2C bus as master
  Wire.begin();
  lcd.begin(16, 2);
  lcd.print("Master");
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x); // transmit x
  Wire.endTransmission(); // stop transmission
  lcd.setCursor(0, 1); // display sent character on LCD
  lcd.print(x);
  x++; // increment x
  if (x > 5) x = 0; // reset x when it reaches 6
  delay(500);
}
