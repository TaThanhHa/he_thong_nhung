void setup() {
  pinMode(13, 1);
  digitalWrite(13,0);
}

void loop() {
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(13, 0);
  delay(2000);
}

