extern "C" void setpin();
extern "C" void turnon();
extern "C" void turnoff();
void setup() {
  setpin();
}
void loop() {
  turnon();
  delay(1000);
  turnoff();
  delay(1000);
}
