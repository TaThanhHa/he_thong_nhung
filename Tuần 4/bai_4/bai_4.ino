#include "TM1637.h"

#define CLK 2
#define DIO 3
int time =0;
int flag = 0;
unsigned long current;
unsigned long last_current = 0;

TM1637 tm1637(CLK, DIO);

void dis_num(int time) {
  tm1637.display(3, time % 10);
  if (time > 9) tm1637.display(2, (time /10 ) % 10);
  if (time > 99) tm1637.display(1, (time /100 ) % 10);
  if (time > 999) tm1637.display(0, (time /1000 ) % 10);
}

void setup() {
  Serial.begin(9600);  
  tm1637.init();      
  tm1637.set(2);        
  tm1637.clearDisplay();
}

void loop() {
  if (Serial.available() ) {
    char c = Serial.read();  
    if (c == 'B') {flag = 1;}
    else if (c == 'S') {flag = 0;}
    else if (c == 'R') {flag = 2;}
  }
  if (flag == 2) {
    time = 0;
    dis_num(time);
    flag = 0;
  }
  if (flag == 1) {
    current = millis();
    if (current - last_current > 1000) {
      time ++;
      if (time == 10000) {time = 0;}
      dis_num(time);
      last_current = current;
    }
  }
}

