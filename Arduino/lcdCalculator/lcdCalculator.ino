#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcdDisplay(0x27, 16, 2);
void add(float, float);

String num1Request = "Input first number: ";
String num2Request = "Input second number: ";
String operators = "+ - * /";
String operatorRequest = "Input Operator: ";
char operatorInput;
int scrollDelay = 350;
float num1;
float num2;
int counter;
int delayTime = 5000;
int waitTime = 2500;

void setup() {
  lcdDisplay.init();
  lcdDisplay.backlight();
  Serial.begin(9600);
}

void loop() {
  num1 = firstNumber();
  num2 = secondNumber();

  operatorInput = chooseOperator();
  switch (operatorInput) {
    case '+':
      add(num1, num2);
      break;
    case '-':
      subtract(num1, num2);
      break;
    case '*':
      product(num1, num2);
      break;
    case '/':
      division(num1, num2);
      break;
    default:
      lcdDisplay.setCursor(0, 0);
      lcdDisplay.print("Wrong Operator!");
      delay(waitTime);
      lcdDisplay.clear();
      /**case '%':
    modulus(num1, num2);
    break;
    */
  }
}

float firstNumber() {
  float num1;

  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("Input First");
  lcdDisplay.setCursor(1, 1);
  lcdDisplay.print("Number: ");
  while (Serial.available() == 0) {
  }
  num1 = Serial.parseFloat();
  lcdDisplay.clear();
  return (num1);
}

float secondNumber() {
  float num2;
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print("Input Second");
  lcdDisplay.setCursor(1, 1);
  lcdDisplay.print("Number: ");
  while (Serial.available() == 0) {
  }
  num2 = Serial.parseFloat();
  lcdDisplay.clear();
  return (num2);
}

char chooseOperator() {
  char operatorInput;
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print(operatorRequest);
  lcdDisplay.setCursor(1, 1);
  lcdDisplay.print(operators);
  while (Serial.available() == 0) {
  }
  operatorInput = Serial.read();
  lcdDisplay.clear();
  return (operatorInput);
}

void add(float num1, float num2) {
  float result;
  result = num1 + num2;
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print(num1);
  lcdDisplay.print("+");
  lcdDisplay.print(num2);
  lcdDisplay.print("=");
  lcdDisplay.print(result);
  delay(delayTime);
  lcdDisplay.clear();
}

void subtract(float num1, float num2) {
  float result;
  lcdDisplay.setCursor(0, 0);
  result = num1 - num2;
  lcdDisplay.print(num1);
  lcdDisplay.print("-");
  lcdDisplay.print(num2);
  lcdDisplay.print("=");
  lcdDisplay.print(result);
  delay(delayTime);
  lcdDisplay.clear();
}

void product(float num1, float num2) {
  float result;
  result = num1 * num2;
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print(num1);
  lcdDisplay.print("*");
  lcdDisplay.print(num2);
  lcdDisplay.print("=");
  lcdDisplay.print(result);
  delay(delayTime);
  lcdDisplay.clear();
}

void division(float num1, float num2) {
  float result;
  lcdDisplay.setCursor(0, 0);
  if (num2 == 0) {
    lcdDisplay.print("Can't Divide by 0.");
    for (counter = 0; counter <= 18; counter++) {
      lcdDisplay.scrollDisplayLeft();
      delay(scrollDelay);
    }
    delay(100);
    lcdDisplay.clear();
  } else {
    result = num1 / num2;
    lcdDisplay.print(num1);
    lcdDisplay.print("/");
    lcdDisplay.print(num2);
    lcdDisplay.print("=");
    lcdDisplay.print(result);
    delay(delayTime);
    lcdDisplay.clear();
  }
}

/**
void modulus(float num1, float num2) {
  float result;
  result = (num1 % num2);
  lcdDisplay.setCursor(0, 0);
  lcdDisplay.print(num1);
  lcdDisplay.print("%");
  lcdDisplay.print(num2);
  lcdDisplay.print("=");
  lcdDisplay.print(result);
}
*/
