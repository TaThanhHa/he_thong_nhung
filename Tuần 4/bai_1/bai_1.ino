#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 display(CLK, DIO);

void setup() {
  display.init();           
  display.set(2);             

  display.display(0, 1);
  display.display(1, 2);
  display.display(2, 3);
  display.display(3, 4);
  delay(2000);

  display.clearDisplay();
  delay(1000);
}
void loop() {
  
}