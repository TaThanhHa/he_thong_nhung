int pos = 0;
unsigned long current;
unsigned long last_current = 0;
int led_bar[8] = {2,3,4,5,6,7,8,9};
#define FLAG 10

void Led(int pos) {
  if (pos == 0) {digitalWrite(led_bar[pos], 1);}
  else {
    digitalWrite(led_bar[pos], 1);
    digitalWrite(led_bar[pos - 1], 0);
  }
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(led_bar[i], 1);
    digitalWrite(led_bar[i], 0);
  }

  pinMode(FLAG, 0);

}

void loop() {
  if(digitalRead(FLAG) ==1 ) {
    current = millis();
    if (current - last_current > 1000) {
      if (pos == 8) {
        digitalWrite(led_bar[pos - 1], 0);
        pos = 0;
      }
      Led(pos);
      pos ++;
      last_current = current;
    }
  } else {
    for (int i = 0; i < 8; i++) {
      digitalWrite(led_bar[i], LOW);
    }
  }

}
