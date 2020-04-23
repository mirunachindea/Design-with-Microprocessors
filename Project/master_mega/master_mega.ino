// include I2C library
#include <Wire.h>
char command;
void setup() {
  // Open I2C bus as master
  Wire.begin();
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop() {
  //if (Serial1.available()) // Read from Bluetooth and send to PC
  // Serial.write(Serial1.read());

  if (Serial.available()) // Read from PC and send to bt
    Serial1.write(Serial.read());

  if (Serial1.available()) {
    command = (char)Serial1.read();
    Serial.println(command);
  }
}

// read message from bluetooth
void serialEvent() {
  while (Serial1.available()) {
    command = (char)Serial1.read();
    Serial.println(command);
    // send message to UNO
    Wire.beginTransmission(9);
    Wire.write(command);
    Wire.endTransmission();
  }
}
