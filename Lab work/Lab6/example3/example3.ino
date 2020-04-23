extern "C" void Serial_Setup();
extern "C" void Print_Hello();
void setup() {
Serial_Setup();
}
void loop() {
Print_Hello();
delay(500);
}
