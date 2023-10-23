#include <Servo.h>
Servo myServo;
int servoPin = 3;
int angle;
int xPin = A0;
int yPin = A1;
int switchPin = 2;
int xVal, yVal, switchVal;
int delayTime = 50;

void setup() {
  myServo.attach(servoPin);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  joyStick();
 
  
}


void joyStick() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  switchVal = digitalRead(switchPin);

  if (switchVal == 0) {
    myServo.write(0);
  }
  angle = map(xVal, 0, 1023, 0 , 180);
  myServo.write(angle);

  delay(delayTime);
  Serial.print("X val: ");
  Serial.print(xVal);
  Serial.print(" Y val: ");
  Serial.print(yVal);
  Serial.print(" Switch Val: ");
  Serial.println(switchVal);
}

void servoControoler() {
  
}