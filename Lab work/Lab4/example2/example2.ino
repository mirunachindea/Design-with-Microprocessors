#include <avr/io.h>
#include <avr/interrupt.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
volatile int myVar;
void setup()
{
  // Initialize Timer1
  cli();// disable the global interrupts system in order to
  //setup the timers
  TCCR1A = 0; // SET TCCR1A and B to 0
  TCCR1B = 0;
  // Set the OCR1A with the desired value:
  OCR1A = 15624;
  // Active CTC mode:
  TCCR1B |= (1 << WGM12);
  // Set the prescaler to 1024:
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  // Enable the Output Compare interrupt (by setting the
  //mask bit)
  TIMSK1 |= (1 << OCIE1A);
  lcd.begin(16, 2);
  lcd.print("Timere cu CTC");
  sei(); // enable global interrupts
}
void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(myVar);
  lcd.setCursor(5, 1);
  lcd.print(TCNT1);
}
ISR(TIMER1_COMPA_vect)
{
  myVar = myVar + 1;
}
