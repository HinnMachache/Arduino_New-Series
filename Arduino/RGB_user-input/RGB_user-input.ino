int myNum;
int greenPin = 3;
int redPin = 6;
int bluePin = 5;
int waitTime = 500;
int counter;
String message = "How many blinks: ";
String colorMessage = "What color would you like? ";
String colorInput;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /**
  Serial.println(message);
  myNum = Serial.parseInt();
  while (Serial.available() == 0){

  }
  delay(waitTime);
  for (counter = 1; counter <= myNum; counter++)
  {
    digitalWrite(greenPin, LOW);
    delay(waitTime);
    digitalWrite(greenPin, HIGH);
    delay(waitTime);
  }
  */
  Serial.println(colorMessage);
  while (Serial.available() == 0) {

  }
  colorInput = Serial.readString();
  delay(500);
  if (colorInput == "red")
  {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }
  if (colorInput == "green")
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  if (colorInput == "blue")
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }
  /**
  else 
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }*/
}
