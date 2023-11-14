int touchPin = 7;
int touchState;
int delayTime = 50;

void setup() {
 pinMode(touchPin, INPUT);
 Serial.begin(9600);

}

void loop() {
  touchState = digitalRead(touchPin);
  if (touchState == 1) {
    Serial.println("TOUCHED");
  }
  else {
    Serial.println("Not Touched!");
  }
  //Serial.println(touchState);
  delay(delayTime);

}
