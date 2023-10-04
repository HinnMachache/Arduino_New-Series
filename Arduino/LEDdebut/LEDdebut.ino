int redLed = 13;
int greenLed = 12;
int blueLed = 11;
int redTime = 300;
int greenTime = 100;
int blueTime = 600;
int count = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (count <= 5) {
    digitalWrite(redLed, HIGH);
    delay(redTime);
    digitalWrite(redLed, LOW);
    delay(redTime);
    count += 1;
  }
  count = 1;
  while (count <= 5) {
    digitalWrite(greenLed, HIGH);
    delay(greenTime);
    digitalWrite(greenLed, LOW);
    delay(greenTime);
    count += 1;
  }
  count = 1;
  while (count <= 5) {
    digitalWrite(blueLed, HIGH);
    delay(blueTime);
    digitalWrite(blueLed, LOW);
    delay(blueTime);
    count += 1;
  }
  count = 1;
}
