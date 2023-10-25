int motionPin = 2;
int ledPin = 3;
int previousMotionPin = LOW;
int currentMotionPin = LOW;

void setup() {
  pinMode(motionPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  previousMotionPin = currentMotionPin;
  currentMotionPin = digitalRead(motionPin);

  // if (previousMotionPin == LOW && currentMotionPin == HIGH) {
  //   digitalWrite(ledPin, HIGH);
  //   Serial.println("Motion Detected!");
  // }  
  // else
  // {
  //   if (previousMotionPin == HIGH && currentMotionPin == LOW) {
  //   digitalWrite(ledPin, LOW);
  //   Serial.println("No Motion Detected!");
  //   }
  // }
  if (currentMotionPin == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Motion Detetected!");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("No Motion Detetected!");
  }

}
