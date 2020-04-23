#include <avr/io.h>
#include <avr/interrupt.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
volatile int myVar;
void setup()
{
  myVar = 0;
  //init Timer1
  cli(); // disable the global interrupts system in order to
        //setup the timers
  TCCR1A = 0; // SET TCCR1A and B to 0
  TCCR1B = 0; // timer set to Normal mode (WGMx3:0 = 0)
  TIMSK1 = (1 << TOIE1); //timer overflow interrupt enable
  //for timer 1
  //Set the prescaler to 1024
  // CPU freq. is 16 MHZ and Timer1 is on 16 bits
  // Counter increment at every dt = 1024 / (16 * 10^6) sec
  // Overflow event occurs at every: dt * 2^16 = 4.194 sec.
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  lcd.begin(16, 2);
  lcd.print("Timers");
  sei(); // enable the global interrupts system
}
void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(myVar);
  lcd.setCursor(5, 1);
  lcd.print(TCNT1);
}
ISR(TIMER1_OVF_vect)
{
  myVar = myVar + 1;
}
