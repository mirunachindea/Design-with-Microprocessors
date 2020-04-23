extern "C" void setpin();
extern "C" char turnspecified(char c);
void setup() {
  setpin();
}
void loop() {
  turnspecified(1);
  delay(1000);
  turnspecified(0);
  delay(1000);
}
