int ledPin = 6;
int buttonPin = 7;
int oldButtonVal = 0;
int newButtonVal;
int ledState = 0;
int delayTime = 100;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  newButtonVal = digitalRead(buttonPin);
  if (oldButtonVal == 0 && newButtonVal == 1) {
    if (ledState == 0) {
      digitalWrite(ledPin, HIGH);
      ledState = 1;
    } else {
      digitalWrite(ledPin, LOW);
      ledState = 0;
    }
    
  }
  oldButtonVal = newButtonVal;
  delay(delayTime);
}
