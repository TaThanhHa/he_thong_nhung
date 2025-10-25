/*
Dùng Timer 1 điều khiển độ sáng của đèn led kết nối với chân D9.
Độ sáng của led được chia ra làm 10 bậc. Cứ sau 1 giây độ sáng sẽ tăng
lên 1 bậc. Khi độ sáng đạt mức cao nhất thì quay lai độ sáng bậc 1.
*/

//do mắt người tốc độ quét chậm nên khi bóng sáng tắt liên tục nhanh chúng ta sẽ thấy ánh sáng yếu hay mạnh
//do thời gian sáng so thời gian tối
#include <TimerOne.h>

const int LED_PIN = 9;
int brightnessLevel = 0;    

void changeBrightness() {
  // Tăng bậc sáng
  brightnessLevel++;
  if (brightnessLevel > MAX_LEVEL) {
    brightnessLevel = 0; 
  }

  // Tính giá trị duty cycle (0–1023)
  int duty = map(brightnessLevel, 0, 9, 0, 1023); // chia khoảng từ 0-1023 ra làm 10 phần và đặt số từ 0-9
  Timer1.setPwmDuty(LED_PIN, duty);  // Cập nhật độ sáng PWM
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // Chu kỳ PWM 1 ms 
  Timer1.initialize(1000);
  Timer1.pwm(LED_PIN, 0); 

  // Tạo ngắt mỗi 1 giây
  Timer1.attachInterrupt(changeBrightness, 1000000);
}

void loop() {
 
}

