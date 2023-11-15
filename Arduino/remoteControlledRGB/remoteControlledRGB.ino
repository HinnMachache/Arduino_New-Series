#include <IRremote.hpp>
#define IR_RECEIVE_PIN 8
int redLed = 3, greenLed = 6, blueLed = 5, ledState = 0;

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    if (IrReceiver.decodedIRData.command == 0x45) {
      // Command 1, DO something, RedLed On
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
    }
    if (IrReceiver.decodedIRData.command == 0x46) {
      // Command 2, DO something, GreedLed On
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
    }
    if (IrReceiver.decodedIRData.command == 0x47) {
      // Command 3, DO something, BlueLed On
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
    }
    if (IrReceiver.decodedIRData.command == 0x44) {
      // Command 4, DO something, Cyan
      analogWrite(redLed, 255);
      analogWrite(greenLed, 155);
      analogWrite(blueLed, 155);
    }
    if (IrReceiver.decodedIRData.command == 0x40) {
      // Command 5, DO something, Magenta
      analogWrite(redLed, 17);
      analogWrite(greenLed, 125);
      analogWrite(blueLed, 17);
    }
    if (IrReceiver.decodedIRData.command == 0x43) {
      // Command 6, DO Something, Yellow
      analogWrite(redLed, 0);
      analogWrite(greenLed, 0);
      analogWrite(blueLed, 255);
    }
    if (IrReceiver.decodedIRData.command == 0x1C) {
      // Command OK, turn Led On
      if (ledState == 0) {
        analogWrite(redLed, 0);
        analogWrite(greenLed, 0);
        analogWrite(blueLed, 0);
        ledState = 1;
      }
      else { //tURN led Off
        analogWrite(redLed, 255);
        analogWrite(greenLed, 255);
        analogWrite(blueLed, 255);
        ledState = 0;
      }
    }
  }
}
