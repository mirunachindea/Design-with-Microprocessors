int b1;
int b2;
int b3;
int b4;
int val;
unsigned long time;

unsigned char stat = 0;
int state =0;


void setup() {
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  val = 1;

  Serial.begin(9600); // need this in order to be able to communicate serial
}

void loop() {
  b1 = digitalRead(4);
  b2 = digitalRead(5);
  b3 = digitalRead(6);
  b4 = digitalRead(7);

  if(b1 == 0) {
    Serial.print("Time: ");
    time = millis();
    Serial.println(time);
    delay(100);
    state = 1;
  } else {
    if (b2 == 0) {
      Serial.print("Time in seconds: ";
      time = millis();
      Serial.println(time/1000);
      delay(100);
      state = 2;
    } else {
      if(b3 == 0 || b4 == 0) {
        state = 0;
      }
    }
  }
  if(state == 1) {
    if(val == 1<<5 ) {
      val = 1;
    } else {
      val = val << 1;
    }
  } else {
    if(state == 2) {
      if(val == 1) {
        val = 1<<5;
      }else {
        val = val >> 1;
      }
    }
  }

  stat = val;
  PORTA = stat;
  delay(50);
}
