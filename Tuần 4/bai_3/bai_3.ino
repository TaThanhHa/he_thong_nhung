#include "TM1637.h"

#define CLK 2
#define DIO 3

TM1637 tm1637(CLK, DIO);

void setup() {
  Serial.begin(9600);  
  tm1637.init();      
  tm1637.set(2);        
  tm1637.clearDisplay();
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();  
    Serial.print(c);

    if (c >= '0' && c <= '9') {
      int num = c - '0'; 
      tm1637.display(1, num);
    }
  }
}

