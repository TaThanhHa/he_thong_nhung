/*
  Dùng timer 1 để điều khiển đèn led tại chân 7 với công thức sau: 1s
sáng + 2s tối.
*/
#include <TimerOne.h>
int count = 0;
void Timer1_ISR() {
  count++;
  if (count < 3) {
    digitalWrite(7,0);
  } else{
    digitalWrite(7,1);
    count = 0;
  }
}
void setup() {
  pinMode(7, 1);
  digitalWrite(7,1);
  Timer1.initialize();
  Timer1.attachInterrupt(Timer1_ISR);
}

void loop() {

}


// void setup() {
//   pinMode(9, 1);
//   Timer1.initialize(3000000); //chu kì 3s (chu kì bao gồm cả thời gian sáng và tối)
//   Timer1.pwm(9, 341); // thời gian sáng 1s =  1/3 chu kì(1024/3)
// }
//  void loop() {}

