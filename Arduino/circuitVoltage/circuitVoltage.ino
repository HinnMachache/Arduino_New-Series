int voltPin = A3;
int readVal;
float voltage = 0;
int delayTime = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(voltPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltPin);
  voltage = (5./1023.) * readVal;
  Serial.println(voltage);
  delay(delayTime);
}
