// Read status of buttons and send it to the PC over the
//serial connection
// Variables for reading the status of the buttons connected
//to the digital pins 4, 5, 6, 7
int b1;
int b2;
int b3;
int b4;

// variable for the transmitted status (as a decimal number)
int stat = 0;

void setup() {
// configure digital pins as inputs
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);

// activate serial communication for displaying the result
// on the PC
Serial.begin(9600);
}
void loop() {
// read BTNs status
b1 = digitalRead(4);
b2 = digitalRead(5);
b3 = digitalRead(6);
b4 = digitalRead(7);
// combine the bits in a decimal number (stat)
stat = 10000 + b4 * 1000 + b3 * 100 + b2 * 10 + b1;
if (b1 == 0){
  Serial.print("Nb. of miliseconds: ");
  Serial.println(millis());
}

if(b2 == 0){
  Serial.print("Nb. of seconds: ");
  Serial.println(millis() / 1000);
}

if(b3 == 0){
  Serial.println("Hello Arduino! :)");
}
//transmit status
Serial.println(stat);
// delay 0.5 sec
delay(500);
}
