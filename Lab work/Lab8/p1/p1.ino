int pin;
int temp;
int transmissionRate;
float resolutionADC = .0049 ; // default ADC resolution for the 5V
float resolutionSensor = .01 ; // sensor resolution = 0.01V/°C
String command = "";
void setup()
{
  Serial.begin(9600); // Serial 0 interface for PC
  Serial1.begin(9600); // Serial 1 interface for Bluetooth module
  pin = 0;
  transmissionRate = 1000;
  command.reserve(2);
}
void loop()
{
  temp = readTempInCelsius(pin);

  if (Serial1.available()) { // Read from Bluetooth and send to PC
    // Serial.write(Serial1.read());
    
  }

  if (Serial.available()) { // Read from PC and send to Bluetooth
    // Serial1.write(Serial.read());
    Serial1.write("Temperature is", temp, "\n");
  }

  delay(1000);
}

float readTempInCelsius(int pin) {
  int reading = analogRead(pin);
  float voltage = reading * resolutionADC;
  // subtract the DC offset and converts the value in
  //degrees (C)
  float tempCelsius = (voltage - 0.5) / resolutionSensor ;
  return tempCelsius;
}
