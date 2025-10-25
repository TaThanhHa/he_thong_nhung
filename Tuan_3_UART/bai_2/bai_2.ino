/*
Từ trên máy tính gửi xuống VĐK 1 chuỗi kí tự bất kì qua cổng UART. VĐK
nhận chuỗi kí tự này rồi gửi lại lên máy tính chuỗi kí tự vừa nhận được.
*/
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {  // khi có chuỗi gửi thì mới làm việc bên trong
    String cmd = Serial.readString();
    Serial.println(cmd);
  }
}
