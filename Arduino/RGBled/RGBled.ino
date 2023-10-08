int greenPin = 3;
int bluePin = 5;
int redPin = 6;
int waitTime = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
  digitalWrite(redPin, LOW);
  delay(waitTime);
  digitalWrite(bluePin,HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(waitTime);
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
  delay(waitTime);
  analogWrite(redPin, 100);
  analogWrite(greenPin, 150);
  analogWrite(bluePin, HIGH);
  delay(waitTime);
  analogWrite(redPin, 100);
  analogWrite(greenPin, 150);
  analogWrite(bluePin, 170);
  delay(waitTime);
  analogWrite(redPin, 50);
  analogWrite(greenPin, 200);
  analogWrite(bluePin, 150);
  delay(waitTime);
  analogWrite(redPin, 90);
  analogWrite(greenPin, 50);
  analogWrite(bluePin, 70);
  delay(waitTime);
}
