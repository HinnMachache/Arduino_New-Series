#include <Servo.h>
int servoPin = 9;
Servo myServo;
int photoPin = A2;
int photoVal;
void setup() {
  Serial.begin(9600);
  pinMode(photoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  photoVal = photoDetector();
  servoController(photoVal);
  Serial.println(photoVal);
}

int photoDetector() {
  int readVal;
  readVal = analogRead(photoPin);
  return (readVal);
}

void servoController(int photoValue) {
  int angle;
  angle = (21. / 168. * photoValue) - 1575. / 168.;
  myServo.write(angle);
}