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

    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Address: ");
      Serial.print( mySwitch.getReceivedValue() >> 16 & 0xffff);
      Serial.print(", value: ");
      Serial.print( mySwitch.getReceivedValue() & 0xffff);
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
    }

    mySwitch.resetAvailable();
  }
}
