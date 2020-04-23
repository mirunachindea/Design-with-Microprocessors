#include <LiquidCrystal.h>
// include I2C library
#include <Wire.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// string for incoming serial data
String inputString = "";

// test if a complete string has been received
boolean stringComplete = false;

void setup() {
  Serial.begin(9600);
  // Open I2C bus as master
  Wire.begin();
  lcd.begin(16, 2);
  inputString.reserve(200);
}

void loop() {

  if (stringComplete) {
    // transmit to device #9
    Wire.beginTransmission(9);
    Wire.write(inputString.c_str()); // transmit x
    // stop transmission
    Wire.endTransmission();
    inputString = "";
    stringComplete = false;
  }

}

void serialEvent() {
  while (Serial.available()) {
    // read the new received byte
    char inChar = (char)Serial.read();
    // check if new line character has been received; if
    //not, add it to the string
    // we do not add new line in input string since it
    //will show an extra character in the LCD
    if (inChar != '\n')
      inputString += inChar;
    // dif the receive character is new line, set the flag
    //so that the loop will know to display
    //the received data
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
