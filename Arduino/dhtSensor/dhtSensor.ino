#include <DHT.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcdDisplay(0x27, 16, 2);
int DHT_pin = 2;
DHT dht11(DHT_pin, DHT11);
float celciusTemp;
float farenheitTemp;
float humidity;
int waitTime = 1000;

void setup() {
  Serial.begin(9600);
  dht11.begin();
  lcdDisplay.init();
  lcdDisplay.backlight();
}

void loop() {
  delay(waitTime);
  celciusTemp = dht11.readTemperature();
  farenheitTemp = dht11.readTemperature(true);
  humidity = dht11.readHumidity();

  if (isnan(celciusTemp) || isnan(farenheitTemp) || isnan(humidity)) {
    //Serial.println("Failed to read data");
    lcdDisplay.setCursor(0,0);
    //lcdDisplay.print(scrollDisplayLeft("Failed to read data");
    lcdDisplay.print("Failed to read data");
    for (int strPos = 0; strPos < 19; strPos++) {
      lcdDisplay.scrollDisplayLeft();
      delay(300);
    }
  } else {
    /**
    Serial.print("Humidity : ");
    Serial.print(humidity);
    Serial.print("%");
    Serial.print(" Temperature: ");
    Serial.print(celciusTemp);
    Serial.print(" °C ~");
    Serial.print(" Temperature: ");
    Serial.print(farenheitTemp);
    Serial.println(" F");
    */
    lcdDisplay.setCursor(0,0);
    lcdDisplay.print("Humidity: ");
    lcdDisplay.setCursor(1,1);
    lcdDisplay.print(humidity);
    delay(2000);
    lcdDisplay.clear();
    lcdDisplay.setCursor(0,0);
    lcdDisplay.print("Temperature: ");
    lcdDisplay.setCursor(1,1);
    lcdDisplay.print(celciusTemp);
    lcdDisplay.print(" C");
    delay(2000);
    lcdDisplay.clear();
    lcdDisplay.setCursor(0,0);
    lcdDisplay.print("Temperature: ");
    lcdDisplay.setCursor(1,1);
    lcdDisplay.print(farenheitTemp);
    lcdDisplay.print(" F");
    delay(2000);
    lcdDisplay.clear();
    
    
  }
}
