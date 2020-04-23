//includes the LCD library
#include <LiquidCrystal.h>
/* LCD RS - pin 7
  LCD Enable - pinl 6
  LCD D4 - pin 5
  LCD D5 - pin 4
  LCD D6 - pin 3
  LCD D7 - pin 2
  The 7-th pin of the LCD is connected to the display brightness
  control potentiometer! */
// Init the LCD with the stated pin numbers
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
unsigned long time;
void setup()
{
  // Sets the no. of rows and columns of the LCD
  lcd.begin(16, 2);
}
void loop()
{
  // Read the number of elapsed seconds from the program
  //start
  time = millis() / 1000;
  // Set the cursor on col 0, row 0 (first row)
  lcd.setCursor(0, 0);
  // Write a string of characters
  lcd.print("Hello Children");
  // Move the cursor in the middle of the second row (row 1)
  lcd.setCursor(7, 1);
  // Display the elapsed time
  lcd.print(time);
}
