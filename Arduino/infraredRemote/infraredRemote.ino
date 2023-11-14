#include <IRremote.hpp>
#define IR_RECEIVE_PIN 6

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); //Start The Receiver

}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); //Print "old" Data
    //IrReceiver.printIRResultShort(&Serial); //Print complete received Data
    //IrReceiver.printIRSendUsage(&Serial); //Print the statement required to send this data
    IrReceiver.resume(); //Enable Receiving of next value
  }

  if (IrReceiver.decodedIRData.command == 0x45) {
    Serial.println("1");
  }
  else if (IrReceiver.decodedIRData.command == 0x46) {
    Serial.println("2");
  }
  else if (IrReceiver.decodedIRData.command == 0x47) {
    Serial.println("3");
  }
  else if (IrReceiver.decodedIRData.command == 0x44) {
    Serial.println("4");
  }
  else if (IrReceiver.decodedIRData.command == 0x40) {
    Serial.println("5");
  }
  else if (IrReceiver.decodedIRData.command == 0x43) {
    Serial.println("6");
  }
  else if (IrReceiver.decodedIRData.command == 0x7) {
    Serial.println("7");
  }
  else if (IrReceiver.decodedIRData.command == 0x15) {
    Serial.println("8");
  }
  else if (IrReceiver.decodedIRData.command == 0x9) {
    Serial.println("9");
  }
  else if (IrReceiver.decodedIRData.command == 0x19) {
    Serial.println("0");
  }
  else if (IrReceiver.decodedIRData.command == 0x16) {
    Serial.println("*");
  }
  else if (IrReceiver.decodedIRData.command == 0xD) {
    Serial.println("#");
  }
  else if (IrReceiver.decodedIRData.command == 0x18) {
    Serial.println("Up");
  }
  else if (IrReceiver.decodedIRData.command == 0x52) {
    Serial.println("Down");
  }
  else if (IrReceiver.decodedIRData.command == 0x8) {
    Serial.println("Left");
  }
  else if (IrReceiver.decodedIRData.command == 0x5A) {
    Serial.println("Right");
  }
  else if (IrReceiver.decodedIRData.command == 0x1C) {
    Serial.println("Ok");
  }
  else {
    Serial.println("Unknown!");
  }
}
