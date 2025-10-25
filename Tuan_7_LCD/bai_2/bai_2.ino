/*
Từ máy tính gửi 1 kí tự tới VĐK qua UART. Nếu nhận kí tự là 1 thì hiển
thị chữ “Hello”, nếu nhận được kí tự 2 thì hiển thị chữ “Goodbye” lên LCD.
*/
#include "rgb_lcd.h"
rgb_lcd lcd;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '1') {
      lcd.clear();
      lcd.print("Hello");
    }

    else if (c == '2') {
      lcd.clear();
      lcd.print("Goodbye");
    }
  }

}
