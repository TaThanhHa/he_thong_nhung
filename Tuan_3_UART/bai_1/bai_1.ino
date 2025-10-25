/*
Khởi tạo kết nối truyền thông với cấu hình baudrate = 9600, 1 start bit, 8 data
bit, 0 parity, 1 stop bit. Gửi lên máy tính dòng chữ “Hello World”.
*/
void setup() {
  Serial.begin(9600); 
}

void loop() {
  Serial.println("Hello Wold"); //in xong xuống dòng
  delay(1000);
}
