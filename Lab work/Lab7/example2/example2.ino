float resolutionADC = .0049 ; // default ADC resolution for the 5V
//reference = 0.049 [V] / unit
float resolutionSensor = .01 ; // sensor resolution = 0.01V/°C

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print("Temp [C]: ");
  float temp = readTempInCelsius(10, 0); // read temp. 10 times
  //and returns the average
  Serial.println(temp); // display the result
  delay(200);
}
float readTempInCelsius(int count, int pin) {
  // read temp. count times from the analog pin
  float sumTemp = 0;
  for (int i = 0; i < count; i++) {
    int reading = analogRead(pin);
    float voltage = reading * resolutionADC;
    // subtract the DC offset and converts the value in
    //degrees (C)
    float tempCelsius = (voltage - 0.5) / resolutionSensor ;
    sumTemp = sumTemp + tempCelsius; // accumulates the
    //readings
  }
  return sumTemp / (float)count; // return the average value
}
