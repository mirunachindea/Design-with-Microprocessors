#include <Servo.h>
// Pins of motor 1
#define mpin00 5
#define mpin01 6
// Pins of motor 2
#define mpin10 3
#define mpin11 11
Servo srv;
char command;
int dir = 1;
void setup() {
  Serial.begin(9600); // Serial 0 interface for PC
  //Serial1.begin(9600);
  // configuration of motor pins as output, initially 0
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);
  // LED pin
  pinMode(13, OUTPUT);
}
// Function to control a motor
// Input: pins m1 and m2, direction and speed
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
// Use of servo
// Set three angles
// When finished, the servo remains in the middle (90 degrees)
void playWithServo(int pin)
{
  srv.attach(pin);
  srv.write(0);
  delay(1000);
  srv.write(180);
  delay(1000);
  srv.write(90);
  delay(1000);
  srv.detach();
}
void loop() {
  if (Serial.available()){
    command = (char)Serial.read();
    if (command == '0'){
      dir = 0;
    }
    else if (command == '1'){
      dir = 1;
    }
  }
    StartMotor (mpin00, mpin01, dir, 128);
    StartMotor (mpin10, mpin11, dir, 128);

}
