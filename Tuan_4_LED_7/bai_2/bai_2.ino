/*
Hiển thị lần lượt các số từ 0 đến F trên Led 0, khoảng cách giữa các lần
hiển thị là 1 giây.
*/

//https://github.com/avishorp/TM1637/blob/master/TM1637Display.cpp

#include "TM1637.h"

#define CLK 2  
#define DIO 3   

TM1637 tm1637(CLK, DIO);

void setup() {
  tm1637.init();
  tm1637.set(2); 
}

void loop() {
  for (int i = 0; i < 16; i++) {
    tm1637.clearDisplay(); // xóa số cũ
    tm1637.display(0, i); // đọc dòng 39 trong git
    delay(1000);
  }
}