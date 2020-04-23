#include <TimerOne.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
volatile int myVar;
void setup(void)
{
  Timer1.initialize(1000000); // init the timing interval
  //for event triggering (1s = 10-6s)
  Timer1.attachInterrupt(ShowMessage); // The function is
  //called at the preset time interval
}
void ShowMessage(void)
{
  lcd.setCursor(0, 0);
  lcd.print(myVar);
  myVar++;
}
void loop(void)
{
  // Do something else …
}
