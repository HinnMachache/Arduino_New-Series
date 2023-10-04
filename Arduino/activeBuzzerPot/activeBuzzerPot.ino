int buzzPin = 7;
int potPin = A3;
int waitTime = 500;
int waittime = 1000;
int numEntered;
String message = "Input a number: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Initiate the serial monitor
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /** Serial.println(message);
  while (Serial.available() == 0) {
  }
  numEntered = Serial.parseInt();
  if (numEntered > 10) {
    digitalWrite(buzzPin, HIGH);
    delay(waitTime);
    digitalWrite(buzzPin, LOW);
  }
  **/
  digitalWrite(buzzPin, HIGH);
  delay(waitTime);
  digitalWrite(buzzPin, LOW);
  delay(waitTime);
  /**
  tone(buzzPin, 1000);
  delay(waitTime);
  tone(buzzPin, 2000);
  delay(waittime);
  tone(buzzPin, 3000);
  delay(waitTime);
  noTone(buzzPin);
  delay(500);
    
**/
}
