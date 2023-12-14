int digitalFlamePin = 7;
int analogFlamePin = A0;
int delayTime = 500;
int flameState, flameValue;

void setup() {
  Serial.begin(9600);
  pinMode(digitalFlamePin, INPUT);
  pinMode(analogFlamePin, INPUT);

}

void loop() {
  flameState = digitalRead(digitalFlamePin);
  flameValue = analogRead(analogFlamePin);

  if (flameState == HIGH) {
    Serial.println("Flame Detected!!!");
  }
  else
  {
    Serial.println("Flame Not Detected!!!");
  }
  Serial.println(flameValue);
  delay(delayTime);

}
