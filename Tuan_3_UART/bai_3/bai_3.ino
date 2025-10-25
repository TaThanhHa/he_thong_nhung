/*
Kết nối 1 đèn Led với 1 chân GPIO (VD chân 7). Từ trên máy tính gửi xuống
VĐK 1 kí tự. Nếu gửi kí tự 1 thì bật led sáng, nếu gửi kí tự 2 thì tắt led.
*/

int flag = 0; // báo đang ở kịch bản nào
void setup() {
  Serial.begin(9600);
  pinMode(7, 1);
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
  digitalWrite(7, flag);
  
}
