int flag = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, 1);
  digitalWrite(13, 0);

}

void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    if (state == '1') {
      flag = 1;
    }
    if (state == '2') {
      flag = 0;
    }
  }
  if (flag == 1) {
   	digitalWrite(13, 1);
  } else{
    digitalWrite(13, 0);
  }
}
