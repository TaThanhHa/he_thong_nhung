// Lập trình điều khiển đèn LED có sẵn trên KIT (nối với chân 13) 
//nhấp nháy với nhịp 1s sáng, 2s tối.

void setup() {
  pinMode(13, 1);
  digitalWrite(13,0);
}

void loop() {
  digitalWrite(13, 1);
  delay(1000);
  digitalWrite(13, 0);
  delay(2000);
}

