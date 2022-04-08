#include <LiquidCrystal.h>
#include <EEPROM.h> 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int sensor = A7;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Sensor PS-10B");
  lcd.setCursor(0, 1);
  lcd.print("Leit. de Pressao");
  delay(1000);
  lcd.clear();
  pinMode(sensor, INPUT);
  Serial.begin(9600); //Inicializa o monitor Serial

  
}

void loop() {

 
  float tensao = analogRead(sensor)*5.0/1023.0;
  float pressao1 = (tensao-1);//Equação da curva do sensor (Y= 0,4X + 1)
  float pressao = pressao1/0.4;
  Serial.print("Tensão de saída do PS-10B (V): ");
  Serial.println(tensao);
  Serial.print("Pressão (Bar): ");
  Serial.println(pressao);
  lcd.setCursor(0, 0);
  lcd.print("Tensao:"); 
  lcd.setCursor(8, 0);
  lcd.print(tensao);
  lcd.setCursor(13,0);
  lcd.print("V");
  lcd.setCursor(0, 1);
  lcd.print("Press.:");
  lcd.setCursor(7, 1);
  lcd.print(pressao);
  lcd.setCursor(13,1);
  lcd.print("Bar");
  delay(1000);
}
