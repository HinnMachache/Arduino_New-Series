int buttonPin = 7;
int ledPin = 6;
int buttonValue;
int delayTime = 100;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonValue = digitalRead(buttonPin);
  ledFunc(buttonValue);
  Serial.println(buttonValue);
  delay(delayTime);
}


void ledFunc(int ledState) {
  if (ledState == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
