/*
Tạo kí tự đặc biệt hình tròn và hiển thị lên LCD. Cho hình tròn này chuyển
động xung quanh màn hình LCD với tốc độ 0.1s/bước.
*/

#include "rgb_lcd.h"
rgb_lcd lcd;

void setup() {
  byte customChar[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B00000,
  B00000
};
  lcd.begin(16,2);
  lcd.createChar(1, customChar);
}

void loop() {
  for (int i = 0; i < 16; i ++) {
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.write(1);
    delay(100);
  }

  for (int i = 16; i >=0; i--) {
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.write(1);
    delay(100);
  }


}
