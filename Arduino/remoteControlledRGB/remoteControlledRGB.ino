#include <IRremote.hpp>
#define IR_RECEIVE_PIN 8
int redLed = 3, greenLed = 6, blueLed = 5, ledState = 0;
int redBrightness = 255, greenBrightness = 255, blueBrightness = 255;
float brightFactor = 1;  //Full Brightness, (100)

void setup() {
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();

    if (IrReceiver.decodedIRData.command == 0x45) {
      // Command 1, DO something, RedLed On
      redBrightness = 1;
      greenBrightness = 255;
      blueBrightness = 255;
    }
    if (IrReceiver.decodedIRData.command == 0x46) {
      // Command 2, DO something, GreedLed On
      redBrightness = 255;
      greenBrightness = 1;
      blueBrightness = 255;
    }
    if (IrReceiver.decodedIRData.command == 0x47) {
      // Command 3, DO something, BlueLed On
      redBrightness = 255;
      greenBrightness = 255;
      blueBrightness = 1;
    }
    if (IrReceiver.decodedIRData.command == 0x44) {
      // Command 4, DO something, Cyan
      redBrightness = 255;
      greenBrightness = 155;
      blueBrightness = 155;
    }
    if (IrReceiver.decodedIRData.command == 0x40) {
      // Command 5, DO something, Magenta
      redBrightness = 17;
      greenBrightness = 125;
      blueBrightness = 17;
    }
    if (IrReceiver.decodedIRData.command == 0x43) {
      // Command 6, DO Something, Yellow on
      redBrightness = 1;
      greenBrightness = 1;
      blueBrightness = 255;
    }
    if (IrReceiver.decodedIRData.command == 0x19) {
      //Commnd 0, DO thing, White On
      redBrightness = 1;
      greenBrightness = 1;
      blueBrightness = 1;
    }
    if (IrReceiver.decodedIRData.command == 0x16) {
      // Command *, Turn Led Off
      redBrightness = 255;
      greenBrightness = 255;
      blueBrightness = 255;
    }
    if (IrReceiver.decodedIRData.command == 0xD) {
      // Command #, Turn Led On
      redBrightness = 0;
      greenBrightness = 0;
      blueBrightness = 0;
    }
    if (IrReceiver.decodedIRData.command == 0x18) {
      // Command UP, Brightness Increase
      brightFactor = brightFactor * 0.9;
      // if (brightFactor > 1) {
      //   brightFactor = 1;
      // }
      // Serial.println(brightFactor);
    }
    if (IrReceiver.decodedIRData.command == 0x52) {
      // Command DOWN, Brightness Decrease
      brightFactor = brightFactor * 2.0;
    }
    // Serial.println(brightFactor);
  }
  Serial.println((redBrightness * brightFactor));
  analogWrite(redLed, redBrightness * brightFactor);
  analogWrite(greenLed, greenBrightness * brightFactor);
  analogWrite(blueLed, blueBrightness * brightFactor);
  ledState = 1;
}
