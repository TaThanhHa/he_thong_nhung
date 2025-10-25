/*
Tập tạo các kí tự đặc 0biệt (Mũi tên lên, mũi tên xuống, hình tròn, hình tam
giác, hình trái tim ...) và lần lượt hiển thị lên trên LCD sau mỗi 1 giây.
*/
//https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight/blob/master/rgb_lcd.cpp

#include "rgb_lcd.h"
rgb_lcd lcd;

void setup() {
  byte customChar[8] = {
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};
  lcd.begin(16,2);
  lcd.createChar(0, customChar);
  lcd.clear();
}

void loop() {
  lcd.write((uint8_t)0); // số 0 thì phải ép kiểu(dòng 306 trong git)
  delay(1000);

}
