
/*
Kết nối thêm biến trở vào KIT qua connector A0. Đo giá trị điện áp của
biến trở. Dòng 1 của LCD hiển thị giá trị số, dòng 2 của LCD hiển thị giá trị
điện áp của biến trở.
*/
#include "rgb_lcd.h"
rgb_lcd lcd;

void setup() {  
  lcd.begin(16, 2);
  pinMode(A0, 0);
}

void loop() {
  int raw = analogRead(A0);
  float Volt = (raw/1024.0) * 5.0;
  lcd.setCursor(0, 0);
  lcd.print("Raw: ");
  lcd.print(raw);
  lcd.setCursor(0, 1);
  lcd.print("Volt: ");
  lcd.print(Volt);
  lcd.print(" V");
  delay(500);
  lcd.clear();

}

