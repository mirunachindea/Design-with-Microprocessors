float resolutionADC = .0049 ; // default ADC resolution for the 5V
//reference = 0.049 [V] / unit
float resolutionSensor = .01 ; // sensor resolution = 0.01V/°C
int led = 13;
int ledVal;
int displayInterval;
int ctTime;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  displayInterval = 200;
}

void loop() {
  Serial.print("Light: ");
  float light = readLightness(10, 0);
  ctTime = millis();
  Serial.println(light); // display the result
 
  ledVal = light / 2;
  if (ledVal > 255){
    ledVal = 255;
  }
  else if (ledVal < 0){
    ledVal = 0;
  }
  
  analogWrite(led, ledVal);
}

float readLightness(int count, int pin) {
  float sumLight = 0;
  for (int i = 0; i < count; i++){
    int reading = analogRead(pin);
    float voltage = reading * resolutionADC;
    float light = (voltage - 0.5) / resolutionSensor ;
    sumLight += light;
  }
  return sumLight / (float)count;
}
