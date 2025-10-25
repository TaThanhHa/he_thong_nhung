/*
Tại chân 9 của KIT, tạo xung PWM với tần số 500Hz để điều khiển độ
sáng của đèn LED. Độ sáng được chia làm 10 độ từ 1 đến 10, sau mỗi
giây độ sáng sẽ tăng lên 1 độ. Khi độ sáng đạt độ 10 thì quay lại độ sáng 1
*/
int brightnessLevel = 1;
void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  if (brightnessLevel > 10) {brightnessLevel = 1}
  int duty = map(brightnessLevel, 1, 10, 0, 255); // tính duty dựa theo i
  analogWrite(9, duty);
  delay(1000);
  brightnessLevel++;
}
