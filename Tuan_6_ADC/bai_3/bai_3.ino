/*
Kết nối biến trở vào chân đầu vào tương tự A0. Đọc giá trị đo được tại
chân A0 và hiển thị lên module led 7 đoạn.
*/

#include "TM1637.h"

#define CLK 2
#define DIO 3
TM1637 led7seg(CLK, DIO);

void dis_num(int raw) {
  led7seg.display(3, raw % 10);
  if (raw > 9) led7seg.display(2, (raw /10 ) % 10);
  if (raw > 99) led7seg.display(1, (raw /100 ) % 10);
  if (raw > 999) led7seg.display(0, (raw /1000 ) % 10);
}

void setup() {  
  Serial.begin(9600);
  led7seg.init();
  led7seg.set(2);        
  led7seg.clearDisplay();
  pinMode(A0, 0);
}

void loop() {
  int raw = analogRead(A0);
  dis_num(raw);
}
