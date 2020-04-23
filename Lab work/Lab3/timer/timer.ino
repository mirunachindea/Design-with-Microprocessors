#include <LiquidCrystal.h>
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

int seconds_elapsed = 0;

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, hourglass1);
  lcd.createChar(1, hourglass2);

}
void loop()
{ 
  for(int i = 0; i <= 100; i++)
  {
    lcd.setCursor(7,0);
    lcd.print(seconds_elapsed);

    lcd.setCursor(10, 0);
    if(seconds_elapsed % 2 == 0)
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
}
