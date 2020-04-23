//include LCD library
#include <LiquidCrystal.h>
#include <Wire.h>
String inputString = ""; // create an empty string to hold the incoming serial data
// Boolean flag to test whether a complete string has been received (enter pressed in serial monitor)
boolean stringComplete = false;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup() {
 // initialize serial interface
 Wire.begin(9);
 Wire.onReceive(receiveEvent);
 
 Serial.begin(9600); // implicit serial frame format
 //initialize lcd
 lcd.begin(16, 2);
 lcd.print("Slave");
 // reserve 200 bytes for the string
 inputString.reserve(200);
}
void loop() {
}

void receiveEvent(int bytes) {
  while(Wire.available()){
    char c=Wire.read();
    inputString+=c;
  }
  Serial.println(inputString);
  inputString = "";
}
/*
SerialEvent is called when new data is received on the RX port
This function is automatically called when the loop is called. If we add delays in loop we will also
delay the showing of the result. */
