int potPin = A3;
int ledPin = 3;
int readVal;
int voltage;
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(potPin);
  voltage = map(readVal, 0, 1023, 0, 255);
  analogWrite(ledPin, voltage);
  Serial.println(voltage);
  delay(100);
}
