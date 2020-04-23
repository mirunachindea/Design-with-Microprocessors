// Include the header for the avr interrupt system
#include "avr/interrupt.h"

// Include the LCD library
#include <LiquidCrystal.h>

// Init the LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

byte nebunie[8] = {
  B00000,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00000
};

volatile int buttonVariable; //public variable that can be
//modified by the ISR

void setup(void)
{
  buttonVariable = 0; // Init the variable shared between
  // the ISR and the main program
  // Set the LCD row and col number
  
  lcd.begin(16, 2);
  lcd.print("Incepe experimentul");
  delay(1000); // perform a 1 sec delay to display this
  //massage on the LCD
  
  // Set pin 21 as input (the pin corresponding to INT0)
  pinMode(21 , INPUT);
  // Set pin 20 as input (the pin corresponding to INT1)
  pinMode(20, INPUT);
  
  pinMode(13, OUTPUT); // Set pin 13 as output
  
  digitalWrite(13, HIGH); // Lit up the onboard LED
  delay(1000);
  
  EIMSK |= (1 << INT0); // Activate INT0
  EIMSK |= (1 << INT1); // Activate INT1
  
  EICRA |= (1 << ISC01); // Specify INT0 triggering
  //behavior: falling edge of the
  EICRA |= (1 << ISC11); // Same behavior for INT1
  
  sei(); // Global interrupt system activation
  digitalWrite(13, LOW); // Turn off the onboard LED
  
  lcd.clear(); // Erase the LCD screen
}
void loop()
{
  // If an interrupt was triggered/executed the LCD has to
  //be erased and the main massage
  //displayed
  if (buttonVariable == 1)
  {
    lcd.clear(); // Erase the LCD
    buttonVariable = 0; // Global variable re-initialized
  }
  
  delay(1000);
  lcd.setCursor(0, 0); // Set the LCD cursor
  lcd.print("Liniste…"); // Display a message
  lcd.setCursor(1, 1);
  lcd.createChar(5, nebunie);
  lcd.write(byte(5));
}

// ISR for INT0 (“INT0_vect” is a predefined name (address)
//for INT0 ISR
ISR(INT0_vect)
{
  digitalWrite(13, !digitalRead(13)); // Change the status
  //of pin 13
  lcd.setCursor(0, 0); // Move the LCD cursor in the top-left
  //corner
  lcd.print("Intrerupem");// Display message
  lcd.setCursor(0, 1);
  lcd.print("ptr stirea zilei");
  buttonVariable = 1;
}
// ISR for INT1
ISR(INT1_vect)
{
  digitalWrite(13, !digitalRead(13));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stirea Doi");
  buttonVariable = 1;
}
