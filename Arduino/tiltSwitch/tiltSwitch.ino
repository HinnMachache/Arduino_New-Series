int tiltPin = 2;
int tiltVal;
int delayTime = 50;
int redLed = 3;
int greenLed = 4;

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

}

void loop() {
  tiltVal = digitalRead(tiltPin);
  tiltLed(tiltVal);
  Serial.println(tiltVal);
  delay(delayTime);

}

void tiltLed(int tiltValue) {
  if (tiltValue == 0) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  }
  else {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  }
}
