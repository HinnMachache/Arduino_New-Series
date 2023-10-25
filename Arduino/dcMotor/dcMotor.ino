 int speedPin = 5;
 int directionPin1 = 4;
 int directionPin2 = 3;
 int motorSpeed = 255;

 void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(directionPin1, HIGH);
  digitalWrite(directionPin2, LOW);
  analogWrite(speedPin, motorSpeed);

}
