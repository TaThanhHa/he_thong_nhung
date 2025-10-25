/*
Lập trình điều khiển đèn LED nối với 1 chân DO nhấp nháy với một tần số cho trước (Tạo hàm
blinkLed(pin_number, duration)), trong đó duration là khoảng thời gian bật tắt đèn.
*/
void blinkLed(int pin_number, int duration) {
  digitalWrite(pin_number,1);
  delay(duration);
  digitalWrite(pin_number,0);
  delay(duration);
}

void setup() {
  pinMode(13, 1);
  digitalWrite(13,0);
}

void loop() {
  blinkLed(13, 500);
}

