
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
    tm1637.clearDisplay();
    tm1637.display(0, i);
    delay(1000);
  }
}