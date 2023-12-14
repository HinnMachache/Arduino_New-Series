int relaySwitch = 2;
int delayTime = 1000;

void setup() {
  pinMode(relaySwitch, OUTPUT);
}

void loop() {
  digitalWrite(relaySwitch, HIGH);
  delay(delayTime);
  digitalWrite(relaySwitch, LOW);
  //delay(delayTime);
  
}
