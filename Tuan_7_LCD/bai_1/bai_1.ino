/*
Kết nối module Grove LCD với kit thông qua connector I2C. Hiển thị
dòng chữ Hello World lên LCD.
*/
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup() 
{
    lcd.begin(16, 2);
    lcd.print("Hello, World!");
}

void loop() 
{
    
}
