// nháy Led sẵn GPIO 13 tần số 2 Hz --> 1s bóng sáng 2 lần tối 2 lần
//led đc nối MCU-Led_GND

void setup() {
  pinMode(13, 1); // khai báo chân 13 là đầu ra
  digitalWrite(13,0); // xuất 0V ra chân 13
}

void loop() {
  digitalWrite(13, 1); // xuất 5V ra chân 13
  delay(250); // trễ tính theo ms
  digitalWrite(13, 0);
  delay(250);
}

