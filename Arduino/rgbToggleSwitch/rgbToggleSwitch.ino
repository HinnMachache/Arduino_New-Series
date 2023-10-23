int buttonPin = 8;
int redLed = 7;
int greenLed = 6;
int blueLed = 5;
int oldButtonValue = 0;
int newButtonValue;
int ledState = 0;
int counter = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin, HIGH);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  newButtonValue = digitalRead(buttonPin);
  Serial.println(newButtonValue);


  if (oldButtonValue == 0 && newButtonValue == 1) {
    switch (ledState) {
      case 0:
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, LOW);
        digitalWrite(blueLed, LOW);
        ledState += 1;
        break;
      case 1:
        digitalWrite(redLed, LOW);
        digitalWrite(greenLed, HIGH);
        digitalWrite(blueLed, HIGH);
        ledState += 1;
        break;
      case 2:
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, LOW);
        digitalWrite(blueLed, HIGH);
        ledState += 1;
        break;
      case 3:
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, HIGH);
        digitalWrite(blueLed, LOW);
        ledState += 1;
        break;
      case 4:
        rgbLed();
        ledState += 1;
        break;
      default:
        digitalWrite(redLed, HIGH);
        digitalWrite(greenLed, HIGH);
        digitalWrite(blueLed, HIGH);
        ledState = 0;
        break;
    }
  }
  oldButtonValue = newButtonValue;
}

void rgbLed() {
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(blueLed, HIGH);
  delay(500);
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, HIGH);
  delay(500);
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(blueLed, LOW);
  delay(500);
}
