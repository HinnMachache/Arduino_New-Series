#include <Stepper.h>
int stepsRevolution = 2048;
int motSpeed = 10;
int delayTime = 500;
Stepper myStepper(stepsRevolution, 8, 10, 9, 11);
int stepperState = 1;
int buttonPin = 7;
int oldButtonVal = 0;
int newButtonVal;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin, HIGH);
}

void loop() {
  //stepperMotor();
  newButtonVal = digitalRead(buttonPin);
  buttonMotor(oldButtonVal, newButtonVal);
  // Serial.println(newButtonVal);
  oldButtonVal = newButtonVal;
}

void stepperMotor() {
  myStepper.step(stepsRevolution);
  delay(delayTime);
  myStepper.step(-stepsRevolution);
  delay(delayTime);
}

void buttonMotor(int oldButtonVal, int newButtonVal) {
  if (oldButtonVal == 0 && newButtonVal == 1) {
    stepperState = stepperState * (-1);
  }
  myStepper.step(stepperState * 1);
}