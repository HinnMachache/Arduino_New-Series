#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Watch me count..");
  delay(1000);
  for (int num = 1; num <= 10; num++) {
    lcd.setCursor(0, 1);
    lcd.print(num);
    delay(300);
  }
  lcd.clear();
}
