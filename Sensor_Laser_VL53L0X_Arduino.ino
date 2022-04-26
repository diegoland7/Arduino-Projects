#include <Wire.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#include "Adafruit_VL53L0X.h"
 
Adafruit_VL53L0X lox = Adafruit_VL53L0X();
 
 
void setup() {
  if (!lox.begin()) {
    while(1);
  }
  lcd.begin(16,2);        
  lcd.clear();
  
}
void loop() {
  lcd.clear();
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false);
  
  
  if (measure.RangeStatus != 4) {
    lcd.setCursor(2,0);
    lcd.print(measure.RangeMilliMeter);
    lcd.setCursor(5,0);
    lcd.print("mm");
    lcd.setCursor(2,1);
    lcd.print(measure.RangeMilliMeter/10);
    lcd.setCursor(4,1);
    lcd.print("cm");
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("fora de alcance!");
  }
  
  /*lcd.setCursor(5,0);
  lcd.print("mm");*/
  delay(200);
}
