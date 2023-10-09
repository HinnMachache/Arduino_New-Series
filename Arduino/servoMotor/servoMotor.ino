#include <Servo.h>
int servoPin = 9;
int waitTime = 2000;
int rotationAngle = 0;
int rotationAngle1 = 180;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.write(rotationAngle);
  delay(waitTime);
  myServo.write(rotationAngle1);
  delay(waitTime);
}
