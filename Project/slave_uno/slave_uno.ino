// include I2C library
#include <Wire.h>
#include <Servo.h>
// Pins of motor 1
#define mpin00 5
#define mpin01 6
// Pins of motor 2
#define mpin10 3
#define mpin11 11
Servo srv;
char command;
int ledR = 10;
int ledL = 9;
void StartMotor (int m1, int m2, int forward, int speed)
{
  if (speed == 0) // stop
  {
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
  }
  else
  {
    if (forward)
    {
      digitalWrite(m2, 0);
      analogWrite (m1, speed); // use PWM
    }
    else
    {
      digitalWrite(m1, 0);
      analogWrite(m2, speed);
    }
  }
}

// Safety function
// Commands motors to stop, then delays
void delayStopped(int ms)
{
  StartMotor (mpin00, mpin01, 0, 0);
  StartMotor (mpin10, mpin11, 0, 0);
  delay(ms);
}

void setup() {
  // Start i2C slave at address 9
  Wire.begin(9);
  // attach a function to be called when we receive
  //something on the I2C bus
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  // configuration of motor pins as output, initially 0
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);

  pinMode(ledR, OUTPUT);
  pinMode(ledL, OUTPUT);
}
void receiveEvent(int bytes) {
   Serial.println("Am primit de la master");
  command = Wire.read(); //read I2C received character
  Serial.println(command);
  //StartMotor (mpin00, mpin01, 1, 0);
  //StartMotor (mpin10, mpin11, 1, 0);
}

void loop() {
  Serial.println("ajhjdfjdgfj");
  if (command == 'F'){ // FORWARD
    StartMotor (mpin00, mpin01, 1, 128);
    StartMotor (mpin10, mpin11, 1, 128);
    digitalWrite(ledR, 0);
    digitalWrite(ledL, 0);
  }
  else if (command == 'B'){ // BACKWARD
    StartMotor (mpin00, mpin01, 0, 128);
    StartMotor (mpin10, mpin11, 0, 128);
    digitalWrite(ledR, 0);
    digitalWrite(ledL, 0);
  }
  else if (command == 'R'){ // LEFT
    StartMotor (mpin00, mpin01, 1, 32);
    StartMotor (mpin10, mpin11, 1, 128);
    digitalWrite(ledR, 1);
    digitalWrite(ledL, 0);
  }
  else if (command == 'L'){ // RIGHT
    StartMotor (mpin00, mpin01, 1, 128);
    StartMotor (mpin10, mpin11, 1, 32);
    digitalWrite(ledR, 0);
    digitalWrite(ledL, 1);
  }
  else if (command == 'S'){ // STOP
    StartMotor (mpin00, mpin01, 0, 0);
    StartMotor (mpin10, mpin11, 0, 0);
    digitalWrite(ledR, 1);
    digitalWrite(ledL, 1);
  }
}
