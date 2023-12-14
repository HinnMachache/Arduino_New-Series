int waterSensor = A1;
int waterPowerPin = 8;
int redLed = 9;
int waterLevel = 0;
int waterVal;
int delayTime = 10;
int SENSOR_MIN = 0;
int SENSOR_MAX = 785;
int level;
int threshHold = 700;

void setup() {
  pinMode(waterSensor, INPUT);
  pinMode(waterPowerPin, OUTPUT); //Power pin to send Output Voltage
  digitalWrite(waterPowerPin, LOW); //Turn Water Sensor Off
  pinMode(redLed, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  //waterDetector();
  waterLevelDetector();

  delay(250);
}

void waterDetector() {
  waterVal = digitalRead(waterSensor); //LOW - NO Water Detected, HIGH -Water Detected
  //Serial.println(waterVal);
  delay(delayTime);

  if (waterVal == 0) {
    Serial.println("Water Absent!");
    digitalWrite(redLed, LOW);
  }
  else {
    Serial.println("Water Present!");
    digitalWrite(redLed, HIGH);
  }
}

void waterLevelDetector(){
  digitalWrite(waterPowerPin, HIGH); //Turn Water Sensor On
  delay(delayTime); //On for 10 milliSeconds
  waterLevel = analogRead(waterSensor);
  digitalWrite(waterPowerPin, LOW);
  Serial.println(waterLevel);
  level = map(waterLevel, SENSOR_MIN, SENSOR_MAX, 0, 4);
  Serial.print("Water Level: ");
  Serial.println(level);

  if (waterLevel > threshHold) {
    digitalWrite(redLed, HIGH);
  }
  else {
    digitalWrite(redLed, LOW);
  }
}
