int buttonPin = 2;
int buttonVal;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin, HIGH);
  Serial.begin(9600);

}

void loop() {
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  delay(50);

}
