int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
byte LEDs = 0b10101010;
byte LEDs1 = 0xFF;
byte LEDs2 = 0b10101010;
byte LEDs3 = 0x00;
int delayTime = 250;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  bitFlipper();
  // digitalWrite(latchPin, LOW);
  // shiftOut(dataPin, clockPin, LSBFIRST, LEDs1);
  // digitalWrite(latchPin, HIGH);
  // delay(delayTime);
  // digitalWrite(latchPin, LOW);
  // shiftOut(dataPin, clockPin, LSBFIRST, LEDs2);
  // digitalWrite(latchPin, HIGH);
  // delay(delayTime);
  // digitalWrite(latchPin, LOW);
  // shiftOut(dataPin, clockPin, LSBFIRST, LEDs3);
  // digitalWrite(latchPin, HIGH);
  // delay(delayTime);
  // LEDs3 += 1;
}

void bitFlipper() {
  // Serial.print(LEDs,BIN);
  // byte bitFliper = ~(LEDs);
  // Serial.print(" - ");
  // Serial.println(bitFliper,BIN);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
  digitalWrite(latchPin, HIGH);
  delay(delayTime);
  LEDs = ~(LEDs);
}
