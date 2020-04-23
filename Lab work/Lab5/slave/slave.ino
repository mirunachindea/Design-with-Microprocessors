#include <LiquidCrystal.h>
// include I2C library
#include <Wire.h>
int x = 0;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
  // Start i2C slave at address 9
  Wire.begin(9);
  // attach a function to be called when we receive
  //something on the I2C bus
  Wire.onReceive(receiveEvent);
  lcd.begin(16, 2);
  lcd.print("Slave");
}
void receiveEvent(int bytes) {
  x = Wire.read(); //read I2C received character
}
void loop() {
  lcd.setCursor(0, 1); // display received character
  lcd.print(x);
}
