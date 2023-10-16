int photoPin = A1;
int buzzerPin = 7;
int photoValue;
int delayValue = 250;
int greenLed = 6;
int redLed = 3;
int delayTime;
void buzzerPhotoDetector(int);

void setup() {
  Serial.begin(9600);
  pinMode(photoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  photoValue = analogRead(photoPin);
  ledResistor(photoValue);
  Serial.println(delayTime);
  buzzerPhotoDetector(photoValue);
  //Serial.println(photoValue);
  //delay(delayValue);
}

void ledResistor(int photoValue) {
  if (photoValue < 400) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  } else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  }
}

void buzzerPhotoDetector(int lightVal) {
  int delayTime;
  delayTime = (-9. / 620.) * lightVal - (-9. * 225. / 620.) + 10.;
  //Serial.println(delayTime);
  digitalWrite(buzzerPin, HIGH);
  delay(delayTime);
  delayMicroseconds()
  digitalWrite(buzzerPin, LOW);
  delay(delayTime);
}