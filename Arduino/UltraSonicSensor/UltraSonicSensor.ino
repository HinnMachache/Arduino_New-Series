int trigPin = 11; //Transmits signals
int echoPin = 12; //Receives Signals
int redLed = 4;
int yellowLed = 5;
int greenLed = 6;
int buzzerPin = 7;
float distance;     //Stores distance variables
int duration; //Duration in microseconds
float realDistance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  realDistance = calculateDistance();
  Serial.print("Distance = ");
  Serial.print(realDistance);
  Serial.println(" cm.");
  ledSecurity(realDistance);
  delay(500);
  
}

float calculateDistance()
{
  digitalWrite(trigPin, LOW); //Clears any signals
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); //Sends Signals
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); //Clears signals
  duration = pulseIn(echoPin, HIGH);  //Receives reflected signals(Pulses)
  distance = (duration * 0.034) / 2;  //Calculates distance in centimetres, speed = 0.034cm/us
  return(distance);
}

void ledSecurity(float distance)
{
  if (distance >= 30.00)
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  else if (distance >= 20.00 && distance <= 29.99)
  {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  else if (distance >= 0.00 && distance <= 19.99)
  {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
     digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.print("Negative Value, Error! ");
  }
}