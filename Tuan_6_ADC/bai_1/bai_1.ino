/*
Kết nối biến trở vào chân đầu vào tương tự A0. Đọc giá trị đo được tại
chân A0 và gửi lên máy tính qua UART giá trị số và giá trị điện áp tại
chân A0.
*/
void setup() {
  pinMode(A0, 0);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(A0); // đọc giá trị raw
  float Volt = (raw/1024.0) * 5.0; // chuyển đổi sang 5V
  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Voltage: ");
  Serial.print(Volt, 2);
  Serial.println(" V");
  delay(500);
}
