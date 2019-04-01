/*
  Simple example for receiving

  https://github.com/sui77/rc-switch/
*/
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableTransmit(D7);  // Receiver on interrupt 0 => that is pin #2
  mySwitch.setProtocol(9);
  mySwitch.setRepeatTransmit(3);

  Serial.println("Start");
}

void loop() {
  // try data sending with a simple start sequence
  Serial.println("Send up long.");
  mySwitch.send(14876163 << 8 | 17, 40);
  delay(1000);
  Serial.println("Send up short.");
  mySwitch.send(14876163 << 8 | 30, 40);
  delay(1000);
  Serial.println("Send center.");
  mySwitch.send(14876163 << 8 | 85, 40);
  delay(1000);
  Serial.println("Send down long.");
  mySwitch.send(14876163 << 8 | 51, 40);
  delay(1000);
  Serial.println("Send down short.");
  mySwitch.send(14876163 << 8 | 60, 40);
  delay(1000);
}
