#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
volatile int buttonVariable;

void setup()
{
  buttonVariable = 0;
  lcd.begin(16, 2);
  lcd.print("A inceput");
  lcd.setCursor(0, 1);
  lcd.print("din nou");
  delay(1000);
  
  // The 2 interrupt pins 21 and 20 declared as inputs with
  //pull-up resistors activated
  pinMode(20 , INPUT);
  pinMode(21 , INPUT);
  digitalWrite(20, HIGH);
  digitalWrite(21, HIGH);
  
  // Atach ISRs to the interrupts corresponding to pins 21
  //and 20 (INT0 and INT1)
  attachInterrupt(digitalPinToInterrupt(20), functieUnu,
                  RISING);
  attachInterrupt(digitalPinToInterrupt(21), functieDoi,
                  CHANGE);
}
void loop()
{
  // Insert here task for normal program flow ….
  lcd.print("Programul principal");
  delay(1000);
}

// First ISR function
void functieUnu()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Functia Unu");
}

// 2-nd ISR function
void functieDoi()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Functia Doi");
}
