int voltPin = A2;
int delayTime = 500;
float readVal;
float voltage;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(voltPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltPin);
  voltage = (5./1023.) * readVal;
  Serial.println(voltage);
  delay(delayTime);
}
