#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdDisplay(0x27, 16, 2);
int trigPin = 11;  //Transmits signals
int echoPin = 12;  //Receives Signals
int redLed = 4;
int yellowLed = 5;
int greenLed = 6;
int buzzerPin = 7;
float distance;  //Stores distance variables
int duration;    //Duration in microseconds
float realDistance;
float averageDistance;
float bucketDistance = 0;
int totalMeasure = 50;
int counter;

void setup() {

  lcdDisplay.init();
  lcdDisplay.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  realDistance = calculateDistance();
  Serial.print("Distance = ");
  Serial.print(realDistance);
  Serial.println(" cm.");
  ledSecurity(realDistance);
  delay(500);
  */
  realDistance = calculateDistance();
  //ledSecurity(realDistance);
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("Distance = ");
  lcdDisplay.print(realDistance);
  lcdDisplay.setCursor(12, 1);
  lcdDisplay.print(" cm.");
  delay(500);
  //lcdDisplay.clear();
}

float calculateDistance() {
  for (counter = 1; counter <= totalMeasure; counter++) 
  {
    digitalWrite(trigPin, LOW);  //Clears any signals
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);  //Sends Signals
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);         //Clears signals
    duration = pulseIn(echoPin, HIGH);  //Receives reflected signals(Pulses)
    delay(50); 
    distance = (duration * 0.034) / 2;  //Calculates distance in centimetres, speed = 0.034cm/us
    bucketDistance = bucketDistance + distance;
  }
  averageDistance = bucketDistance / totalMeasure;
  return (averageDistance);
}

void ledSecurity(float distance) {
  if (distance >= 30.00) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
  } else if (distance >= 20.00 && distance <= 29.99) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
  } else if (distance >= 0.00 && distance <= 19.99) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
    //Serial.print("Negative Value, Error! ");
    lcdDisplay.setCursor(0, 0);
    lcdDisplay.print("Negative Value, Error! ");
    for (int strLen = 0; strLen < 23; strLen++) {
      lcdDisplay.scrollDisplayLeft();
      delay(150);
    }
  }
}