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
const unsigned char digits[] = {12, 14, 10, 15}; // The number to be
//displayed is 1234. You can change it.

void setup ()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); // The three pins connected to
  // the shift register must be output pins
}

void loop()
{
  for (char i = 0; i <= 3; i++) // For each of the 4 digits
  {
    unsigned char digit = digits[i]; // the current digit
    unsigned char cathodes = ~ssdlut[digit]; // The
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
}
