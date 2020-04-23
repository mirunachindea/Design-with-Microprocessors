#include "external_functions.h"
void setup() {
  compute();
  uint8_t val = result;
  Serial.begin(9600);
  Serial.println(val);
}
void loop() { }
