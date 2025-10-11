#include <TimerOne.h>
int pos = 0;
int flag = 0;
uint8_t led_bar[8] = {2,3,4,5,6,7,8,9};


void led(int i){
  if (i == 0) {
    digitalWrite(led_bar[0], 1); 
    digitalWrite(led_bar[1], 1);
    digitalWrite(led_bar[2], 1); 
  }
  else if (i < 6) {
    digitalWrite(led_bar[i], 1);
  	digitalWrite(led_bar[i+1], 1);
    digitalWrite(led_bar[i+2], 1);
  	digitalWrite(led_bar[i-1], 0);
  } else {
    digitalWrite(led_bar[12- i], 1);
    digitalWrite(led_bar[11-i], 1);
    digitalWrite(led_bar[10- i], 1);
    digitalWrite(led_bar[13 -i], 0);
  }
}

void remove_led() {
  if (flag == 1) {
    if (pos > 10) pos = 1;
    led(pos);
    pos ++;
  }else {
    for (int i = 0; i < 8; i ++) {
      digitalWrite(led_bar[i],0);
    }
  }
}

void setup() {
  for (int i = 0; i < 8; i ++) {
    pinMode(led_bar[i], 1);
    digitalWrite(led_bar[i],0);
  }
  Timer1.initialize();
  Timer1.attachInterrupt(remove_led);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '1') {
      flag = 1;
    }
    if (c == '2') {
      flag = 0;
    }
  }
}
