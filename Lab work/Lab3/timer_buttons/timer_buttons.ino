// Include the header for the avr interrupt system
#include "avr/interrupt.h"
// Include the LCD library
#include <LiquidCrystal.h>
// Init the LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

byte hourglass1[8] = {
  B00000,
  B11111,
  B01110,
  B00100,
  B01110,
  B11111,
  B00000,
};

byte hourglass2[8] = {
  B00000,
  B10001,
  B11011,
  B00100,
  B11011,
  B10001,
  B00000,
};

volatile int buttonVariable;
volatile int seconds_elapsed = 0;
int start = 0;
bool first = true;
void setup() {
  buttonVariable = 0;
  lcd.begin(16, 2);
  lcd.createChar(0, hourglass1);
  lcd.createChar(1, hourglass2);


  pinMode(21, INPUT);
  pinMode(20, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  EIMSK |= (1 << INT0); // Activate INT0
  EIMSK |= (1 << INT1); // Activate INT1
  EICRA |= (1 << ISC01); // Specify INT0 triggering
  //behavior: falling edge of the
  EICRA |= (1 << ISC11); // Same behavior for INT1
  sei(); // Global interrupt system activation
  digitalWrite(13, LOW); // Turn off the onboard LED
  lcd.clear(); // Erase the LCD screen

}

void loop() {

  // reset
  if (buttonVariable == 1)
  {
    lcd.clear();
    seconds_elapsed = 0;
    buttonVariable = 0;
  }

  // start or stop
  if (buttonVariable == 2)
  {
    start = (start == 0) ? 1 : 0;
    buttonVariable = 0;
    first = false;
  }

  if (start == 1)
  {

    lcd.setCursor(7, 0);
    lcd.print(seconds_elapsed);

    lcd.setCursor(10, 0);
    if (seconds_elapsed % 2 == 0)
    {
      lcd.write(byte(0));
    }
    else
    {
      lcd.write(byte(1));
    }

    delay(1000);
    lcd.clear();
    seconds_elapsed += 1;

  }

  else 
  {
    lcd.setCursor(7, 0);
    lcd.print(seconds_elapsed);

    lcd.setCursor(10, 0);
    if (seconds_elapsed % 2 == 0)
    {
      lcd.write(byte(0));
    }
    else
    {
      lcd.write(byte(1));
    }
    
  }

  

}

// reset
ISR(INT0_vect)
{
  buttonVariable = 1;
}
// ISR for INT1
ISR(INT1_vect)
{
  buttonVariable = 2;
}
