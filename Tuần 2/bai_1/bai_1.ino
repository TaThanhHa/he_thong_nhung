// nháy Led sẵn GPIO 13 tần số 2 Hz

void setup() {
  pinMode(13, 1);
  digitalWrite(13,0);
}

void loop() {
  digitalWrite(13, 1);
  delay(250);
  digitalWrite(13, 0);
  delay(250);
}

