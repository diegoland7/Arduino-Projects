#include <Ultrasonic.h>
#include <LiquidCrystal.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 36
#define pino_echo 46
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  lcd.begin(16,2); //Inicializa LCD
  lcd.clear(); //Limpa o LCD
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  double volume, raio, alt1, alt2, altmm, volume2;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);

  raio = 30;
  alt1 = 400;
  altmm = cmMsec*10;
  alt2 = (alt1 - altmm);
  volume = (3.14159*90*alt2);
  volume2 = volume/100000;
  
  lcd.setCursor(0,0);
  lcd.print("Dist(mm):");
  //lcd.print(" ");
  lcd.setCursor(9,0);
  lcd.print(altmm,3);
  lcd.setCursor(0,1);
  lcd.print("vol(L):");
  //lcd.print(" ");
  lcd.setCursor(9,1);
  lcd.print(volume2,5);
  
  //Exibe informacoes no serial monitor
  /*Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);*/
  Serial.print(" - Volume: ");
  Serial.println(volume);
  Serial.print(" - Volume2: ");
  Serial.println(volume2);
  delay(1000);
}
