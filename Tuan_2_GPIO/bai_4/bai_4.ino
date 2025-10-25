/*
Lập trình điều khiển thanh Led (Led bar) với yêu cầu sau:
+ Các Led sáng lần lượt từ Led0 đến Led7, mỗi Led sáng 1s rồi chuyển sang Led kế tiếp.
+ Sau khi Led7 sáng lại chuyển tiếp về Led0 và tiếp tục.
+ Sử dụng 1 GPIO làm DI. Nếu chân này có giá trị 1 thì led nháy, nếu có giá trị 0 thì led tắt.
Led_bar phải nối chân COM xuống đất
*/

int pos = 0; // vị trí
unsigned long current; // thời điểm hiện tại
unsigned long last_current = 0; // thời điểm quá khứ
int led_bar[8] = {2,3,4,5,6,7,8,9}; // led_bar(ko dùng chân 0,1 vì liên quan đến UART)
#define FLAG 10 // chân báo - DI

void Led(int pos) {
  if (pos == 0) {digitalWrite(led_bar[pos], 1);}
  else {
    digitalWrite(led_bar[pos], 1);
    digitalWrite(led_bar[pos - 1], 0);
  }
}

void setup() {
  // khái báo các chân led_bar là đầu ra và tắt đèn
  for (int i = 0; i < 8; i++) {
    pinMode(led_bar[i], 1);
    digitalWrite(led_bar[i], 0);
  }

  // khai báo chân DI làm đầu vào
  pinMode(FLAG, 0);

}

void loop() {
  if(digitalRead(FLAG) == 1 ) {
    current = millis(); //millis trả về giá trị thời gian tính từ lúc chạy
    if (current - last_current > 1000) { // đc 1s
      if (pos == 8) {
        digitalWrite(led_bar[pos - 1], 0);
        pos = 0;
      }
      Led(pos);
      pos ++;
      last_current = current; // gắn lại thời điểm đã sáng trc đó
    }
  } else {
    for (int i = 0; i < 8; i++) {
      digitalWrite(led_bar[i], LOW);
    }
  }

}
