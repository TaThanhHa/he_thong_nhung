
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readString();
    Serial.println(cmd);
  }

}
