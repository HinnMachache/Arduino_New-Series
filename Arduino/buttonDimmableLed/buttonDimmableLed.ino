int buttonBright = 2;
int buttonDim = 8;
int yellowLed = 6;
int buzzPin = 5;
int brightButton;
int dimButton;
int ledValue = 0;
int delayTime = 500;

void setup() {
  pinMode(buttonBright, INPUT);
  pinMode(buttonBright, HIGH);
  pinMode(buttonDim, INPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(buttonDim, HIGH);
  Serial.begin(9600);
}

void loop() {
  brightButton = digitalRead(buttonBright);
  dimButton = digitalRead(buttonDim);
  delay(100);
  Serial.println("LedValue");
  Serial.println(ledValue);

  if (brightButton == 1) {
    ledValue += 10;
  }
  if (ledValue > 255) {
    ledValue = 255;
    digitalWrite(buzzPin, HIGH);
    delay(delayTime);
    digitalWrite(buzzPin, LOW);
  }


  if (dimButton == 1) {
    ledValue -= 10;
  }

  if (ledValue < 0) {
    ledValue = 0;
    digitalWrite(buzzPin, HIGH);
    delay(delayTime);
    digitalWrite(buzzPin, LOW);
  }

  analogWrite(yellowLed, ledValue);
 
}


