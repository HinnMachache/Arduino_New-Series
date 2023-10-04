int redPin = 13;
int count = 1;
int delayTime1 = 100;
int delayTime2 = 500;
int longWait = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (count <= 3)
  {
    digitalWrite(redPin, HIGH);
    delay(delayTime1);
    digitalWrite(redPin, LOW);
    delay(delayTime1);
    count += 1;
  }
  delay(longWait);
  count = 1;
  while (count <= 3)
  {
    digitalWrite(redPin, HIGH);
    delay(delayTime2);
    digitalWrite(redPin, LOW);
    delay(delayTime2);
    count += 1;
  }
  delay(longWait);
  count = 1;
}
