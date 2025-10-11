#include <TimerOne.h>
void Timer1_ISR() {
  digitalWrite(7, !digitalRead(7));
}
void setup() {
  pinMode(7, 1);
  digitalWrite(7,0);
  Timer1.initialize(500000); //500ms
  Timer1.attachInterrupt(Timer1_ISR);
}

void loop() {
  // put your main code here, to run repeatedly:

}


