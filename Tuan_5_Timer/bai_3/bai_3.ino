/*
3. Dùng Timer 1 để điều khiển thanh Led (Led bar) với yêu cầu sau:
+ Các Led sáng lần lượt từ Led0 đến Led7 theo từng cụm 3 Led liên
tiếp, mỗi cụm sáng 1s rồi chuyển sang cụm kế tiếp.
+ Sau khi Led7 sáng lại đổi chiều về Led0.
+ Sau khi Led0 sáng lại đổi chiều về Led7 và tiếp tục.
*/
#include <TimerOne.h>
int pos = 0;
uint8_t led_bar[8] = {2,3,4,5,6,7,8,9};


void led(int i){
  if (i == 0) {
    digitalWrite(led_bar[0], 1); 
    digitalWrite(led_bar[1], 1);
    digitalWrite(led_bar[2], 1); 
  }
  else if (i < 6) {
    digitalWrite(led_bar[i], 1);
  	digitalWrite(led_bar[i+1], 1);
    digitalWrite(led_bar[i+2], 1);
  	digitalWrite(led_bar[i-1], 0);
  } else {
    digitalWrite(led_bar[12- i], 1);
    digitalWrite(led_bar[11-i], 1);
    digitalWrite(led_bar[10- i], 1);
    digitalWrite(led_bar[13 -i], 0);
  }
}

void remove_led() {
  if (pos > 10) pos = 1;
  led(pos);
  pos ++;
}

void setup() {
  for (int i = 0; i < 8; i ++) {
    pinMode(led_bar[i], 1);
    digitalWrite(led_bar[i],0);
  }
  Timer1.initialize();
  Timer1.attachInterrupt(remove_led);
}

void loop() {
}
