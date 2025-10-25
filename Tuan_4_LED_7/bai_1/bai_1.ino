/*
Kết nối module Grove TM1637 vào connector D2 trên Kit Seeeduino
Lotus bằng cáp. Khai báo thư viện TM1637.h, khởi tạo thư viện và hiển
thị số 1,2,3,4 lên 4 đèn led trên module.
*/

//https://github.com/avishorp/TM1637/blob/master/TM1637Display.cpp

#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 Led7(CLK, DIO); //khởi tạo đối tượng

void setup() {
  Led7.init();  // khởi tạo LED 7 đoạn        
  Led7.set(2);  // độ sáng           

  Led7.display(0, 1); // tham số đầu chỉ vị trí sáng (0 là số ngoài cùng bên phải)
  Led7.display(1, 2);
  Led7.display(2, 3);
  Led7.display(3, 4);
}
void loop() {
  
}