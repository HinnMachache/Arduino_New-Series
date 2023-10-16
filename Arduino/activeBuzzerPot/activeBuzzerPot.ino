void potBuzzer(int);
int buzzPin = 7;
int potPin = A3;
int waitTime = 500;
int waittime = 1000;
int numEntered;
int readVal;
String message = "Input a number: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initiate the serial monitor
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /** Serial.println(message);
  while (Serial.available() == 0) {
  }
  numEntered = Serial.parseInt();
  if (numEntered > 10) {
    digitalWrite(buzzPin, HIGH);
    delay(waitTime);
    digitalWrite(buzzPin, LOW);
  }
  **/
  readVal = analogRead(potPin);
  potBuzzer(readVal);
  //Serial.println(readVal);
  //delay(100);
  potBuzzer(readVal);
  // Serial.println(readVal);
  // delay(100);
  // if (readVal > 1000) {       //Buzzer Beep if ReadVal > 1000
  //   digitalWrite(buzzPin, HIGH);
  //   delay(waitTime);
  //   digitalWrite(buzzPin, LOW);
  //   delay(waitTime);
}

void potBuzzer(int potValue) {
  int delayTime;
  delayTime = (-9940. / 1023. * potValue) + 10000;
  //Serial.println(delayTime);
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(delayTime);
}

/**
  tone(buzzPin, 1000);
  delay(waitTime);
  tone(buzzPin, 2000);
  delay(waittime);
  tone(buzzPin, 3000);
  delay(waitTime);
  noTone(buzzPin);
  delay(500);
    
**/
