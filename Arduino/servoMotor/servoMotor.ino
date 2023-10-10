#include <Servo.h>
int servoPin = 9; 
int waitTime = 2000;
int rotationAngle;
int rotationAngle1 = 180;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /**
  myServo.write(rotationAngle);
  delay(waitTime);
  myServo.write(rotationAngle1);
  delay(waitTime);
  */
  for (rotationAngle = 0; rotationAngle <= 180; rotationAngle++)
  {
    myServo.write(rotationAngle);
    delay(30);
  }
  /**
  for (rotationAngle = 180; rotationAngle >= 0; rotationAngle--)
  {
    myServo.write(rotationAngle);
    delay(15);
  }
  */
}
