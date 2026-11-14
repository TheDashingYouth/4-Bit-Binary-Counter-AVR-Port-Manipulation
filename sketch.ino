
byte counter = 0;

void setup() {

  Serial.begin(9600);

  DDRB = (DDRB & 0xF0) | 0x0F;

  DDRB &= ~(1 << DDB4);

  PORTB = (PORTB & 0xE0) | (1 << PORTB4);

  PORTB = (PORTB & 0xF0) | counter;

  Serial.println(counter);
}

void loop() {

  if (!(PINB & (1 << PINB4))) {

    delay(50);

    if (!(PINB & (1 << PINB4))) {

      counter++;

      if (counter > 15) {
        counter = 0;
      }

      PORTB = (PORTB & 0xF0) | (counter & 0x0F);

      Serial.println(counter);

      while (!(PINB & (1 << PINB4))) {
      }

      delay(50);
    }
  }
}

