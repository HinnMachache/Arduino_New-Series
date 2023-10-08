int j = 0;
int waitime = 2000;
float radius = 7.0;
float area;
float pi = 3.14;
String myString = "J = ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  area = pi * radius * radius;
  Serial.print("A Circle of Radius ");
  Serial.print(radius);
  Serial.print(" Has an area of ");
  Serial.println(area);
  delay(waitime);
}
