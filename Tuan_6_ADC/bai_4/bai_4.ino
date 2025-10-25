/*
Dùng biến trở để điều khiển độ sáng của đèn led kết nối với chân 10,
thông báo độ sáng lên máy tính theo % qua UART.
*/
void setup() {
  pinMode(10,1);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(A0);
  int duty = map(raw, 0, 1023, 0,255);
  analogWrite(10, duty);
  float duty_percent = raw/1023.0 *100.0;
  Serial.println(duty_percent);
  delay(100);
}
