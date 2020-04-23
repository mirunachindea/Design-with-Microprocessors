int latchPin = 4;
int clockPin = 7;
int dataPin = 8; // SSD pins

const unsigned char ssdlut[] =
{ 0b00111111, // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00000111,  // 7
  0b01111111,  // 8
  0b01101111,  // 9
  0b01110111,  // A
  0b01111100,  // b
  0b00111001,  // C
  0b01011110,  // d
  0b01111001,  // E
  0b00111111
};
const unsigned char anodelut[] = {0b00000001, 0b00000010,
                                  0b00000100, 0b00001000
                                 };
const unsigned char digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // The number to be
//displayed is 1234. You can change it.

const int lutsize = 10;

int number = 0;
void setup ()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); // The three pins connected to
  // the shift register must be output pins
}
void loop()
{
  unsigned char cathodes;
  for (char i = 2; i <= 3; i++) // For the first 2 digits
  {
    if (i == 3){
        int cz = number % 10;
        unsigned char digit = digits[cz]; // the current digit
        cathodes = ~ssdlut[digit];
    }

    else if (i == 2){
        int cu = number / 10;
        unsigned char digit = digits[cu]; // the current digit
        cathodes = ~ssdlut[digit];
    }
    
    // The
    //cathodes of the current digit, we’ll
    //negate the value from the original LUT
    digitalWrite(latchPin, LOW); // Activate the latch to
    //allow writing
    shiftOut(dataPin, clockPin, MSBFIRST, cathodes); //
    //shift out the cathode byte
    shiftOut(dataPin, clockPin, MSBFIRST, anodelut [i] );
    // shift out the anode byte
    digitalWrite(latchPin, HIGH); // De-activate the latch
    //signal
    delay(2); // Short wait
  }

  number ++;
  delay(1000);
}
