/*
  Simple example for receiving

  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(digitalPinToInterrupt(D7));  // Receiver on interrupt 0 => that is pin #2
  Serial.println("Start");
}

void loop() {
  if (mySwitch.available()) {

    int value = mySwitch.getReceivedValue();
    delay(100);

    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Address: ");
      Serial.print( mySwitch.getReceivedValue() >> 8 & 0xffffffff);
      Serial.print(", value: ");
      Serial.print( mySwitch.getReceivedValue() & 0xff);
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
    }

    mySwitch.resetAvailable();
  }
}
