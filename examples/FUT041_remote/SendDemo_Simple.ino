/*
  Simple example for receiving

  https://github.com/sui77/rc-switch/
*/
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableTransmit(D7);  // Receiver on interrupt 0 => that is pin #2
  Serial.println("Start");
}

void loop() {
  Serial.println("Send simple: left");
  mySwitch.send(41490 << 16 | 43699, 32);
  delay(2000);
  Serial.println("Send inverted with repeats: right");
  mySwitch.send(41490 << 16 | 44984, 32);
  delay(2000);
  Serial.println("Send inverted with repeats: up");
  mySwitch.send(41490 << 16 | 42671, 32);
  delay(2000);
  Serial.println("Send inverted with repeats: down");
  mySwitch.send(41490 << 16 | 43442, 32);
  delay(2000);
  Serial.println("Send inverted with repeats: center");
  mySwitch.send(41490 << 16 | 41129, 32);
  delay(2000);
}
