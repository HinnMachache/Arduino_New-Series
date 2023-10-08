int yellowPin_1 = 4;
int yellowPin_2 = 5;
int yellowPin_3 = 6;
int yellowPin_4 = 7;
int delayTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin_1, OUTPUT);
  pinMode(yellowPin_2, OUTPUT);
  pinMode(yellowPin_3, OUTPUT);
  pinMode(yellowPin_4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, LOW);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, LOW);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, LOW);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);

  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, LOW);
  delay(delayTime);


  digitalWrite(yellowPin_4, HIGH);
  digitalWrite(yellowPin_3, HIGH);
  digitalWrite(yellowPin_2, HIGH);
  digitalWrite(yellowPin_1, HIGH);
  delay(delayTime);
  
}
