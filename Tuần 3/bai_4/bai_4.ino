int flag = 0;
int pos = 0;
uint8_t led_array[8] = {2,3,4,5,6,7,8,9};
unsigned long current;
unsigned long last_current = 0;
void led(int i){
  if (i == 0) {
    digitalWrite(led_array[0], 1); 
    digitalWrite(led_array[1], 1);
    digitalWrite(led_array[2], 1); 
  }
  else if (i < 6) {
    digitalWrite(led_array[i], 1);
  	digitalWrite(led_array[i+1], 1);
    digitalWrite(led_array[i+2], 1);
  	digitalWrite(led_array[i-1], 0);
  } else {
    digitalWrite(led_array[12- i], 1);
    digitalWrite(led_array[11-i], 1);
    digitalWrite(led_array[10- i], 1);
    digitalWrite(led_array[13 -i], 0);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i ++) {
    pinMode(led_array[i], 1);
    digitalWrite(led_array[i],0);
  }
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
  if (flag == 1) {
    current = millis();
    if (pos > 10) pos = 1;
    if ((current - last_current) > 1000) {
      led(pos);
      last_current = current;
      pos ++;
    }
  }else {
    for (int i = 0; i < 8; i ++) {
      digitalWrite(led_array[i], 0);
    }
  }
}
