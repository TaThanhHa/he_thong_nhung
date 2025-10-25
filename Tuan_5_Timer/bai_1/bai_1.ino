/*
  1. Dùng timer 1 để tạo xung điều khiển đèn led tại chân 7 với tần số 1Hz
  1 s thì sáng tắt 1 lần 
*/
#include <TimerOne.h>
void Timer1_ISR() {
  digitalWrite(7, !digitalRead(7));
}
void setup() {
  pinMode(7, 1);
  digitalWrite(7,0);
  Timer1.initialize(500000); //500ms - sau thời gian này sẽ nhảy vào hàm ngắt
  Timer1.attachInterrupt(Timer1_ISR); //hàm xử lý ngắt
}

void loop() {

}

// nếu bắt dùng xùn PWM
// void setup() {
//   pinMode(9, 1);
//   Timer1.initialize(); //chu kì 1 s
//   Timer1.pwm(9, 512); //thời gian sáng là 500ms = 1/2 chu kì (1024/2)
// }
//  void loop() {}

