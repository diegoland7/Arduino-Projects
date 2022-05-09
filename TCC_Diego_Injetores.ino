#include <LiquidCrystal.h>

#define INJ1 13
#define INJ2 12
#define INJ3 11
#define INJ4 10

#define LEFT 14
#define ENTER 15

#define DRENO1 17
#define DRENO2 18
#define DRENO3 19
#define DRENO4 7

//////////////////////////Pinos Display//////////////////////////////

#define pinBackLight 7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
////////////////////////////////////////////////////////////////////

unsigned long tempototal = 10000;
unsigned long tempototalestatico = 5000;
unsigned long tempo2 = 0;
unsigned long tempoentrepulsos = 60;
int sensor = A2;
int flag2 = 0;
int flag1 = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(INJ1, OUTPUT);
  pinMode(INJ2, OUTPUT);
  pinMode(INJ3, OUTPUT);
  pinMode(INJ4, OUTPUT);
  pinMode(DRENO1, OUTPUT);
  pinMode(DRENO2, OUTPUT);
  pinMode(DRENO3, OUTPUT);
  pinMode(DRENO4, OUTPUT);
  pinMode(OP1, INPUT);
  pinMode(OP2, INPUT);
  pinMode(sensor, INPUT);
  pinMode(pinBackLight, OUTPUT);
  digitalWrite(pinBackLight, HIGH);
  
  digitalWrite(INJ1, 0);
  digitalWrite(INJ2, 0);
  digitalWrite(INJ3, 0);
  digitalWrite(INJ4, 0);
  digitalWrite(DRENO1,0);
  digitalWrite(DRENO2,0);
  digitalWrite(DRENO3,0);
  digitalWrite(DRENO4,0);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Diego G Land");
  lcd.setCursor(0, 1);
  lcd.print("Teste__Injetores");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("[1] Estatico");
  lcd.setCursor(0, 1);
  lcd.print("[2] Equalizacao");

}


void loop()
{
  float tensao = analogRead(sensor)*5.0/1023.0;
  float pressao1 = (tensao-1);//Equação da curva do sensor (Y= 0,4X + 1)
  float pressao = pressao1/0.4;

  
  
  if (digitalRead(OP2))
  {
    flag2 = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("**Removendo Ar**");
    lcd.setCursor(0, 1);
    lcd.print("Iniciando......");
    digitalWrite(INJ1, 1);
    digitalWrite(DRENO1,1);
    digitalWrite(DRENO2,1);
    digitalWrite(DRENO3,1);
    digitalWrite(DRENO4,1);
    delay(1000);
    digitalWrite(INJ1, 0);
    digitalWrite(INJ2, 1);
    delay(1000);
    digitalWrite(INJ2, 0);
    digitalWrite(INJ3, 1);
    delay(1000);
    digitalWrite(INJ3, 0);
    digitalWrite(INJ4, 1);
    delay(1000);
    digitalWrite(INJ4, 0);
    digitalWrite(DRENO1,0);
    digitalWrite(DRENO2,0);
    digitalWrite(DRENO3,0);
    digitalWrite(DRENO4,0);
    lcd.clear();
	
    lcd.setCursor(0, 1);
    lcd.print("TEMPO(s): ");
    
    
    tempo2 = millis();
      while((millis() - tempo2) < tempototal)
      {
        tensao = analogRead(sensor)*5.0/1023.0;
 		pressao1 = (tensao-1);//Equação da curva do sensor (Y= 0,4X + 1)
  		pressao = pressao1/0.4;
        lcd.setCursor(0, 0);
  		lcd.print("Press.:");
  		lcd.setCursor(7, 0);
  		lcd.print(pressao);
  		lcd.setCursor(13,0);
  		lcd.print("Bar");
        digitalWrite(INJ1, 1);
        digitalWrite(INJ2, 1);
        digitalWrite(INJ3, 1);
        digitalWrite(INJ4, 1);
        delay(5);
        digitalWrite(INJ1, 0);
        digitalWrite(INJ2, 0);
        digitalWrite(INJ3, 0);
        digitalWrite(INJ4, 0);
        delay(tempoentrepulsos);
        lcd.setCursor(10, 1);
        int strr1 = (tempototal-(millis() - tempo2))/1000;
        String strr2 = " ";
        String str1 =  strr1 + strr2;
        lcd.print(str1);
        if (digitalRead(OP2) && flag2 == 1)
        {
          break;
        }

      }
      digitalWrite(INJ1, 0);
      digitalWrite(INJ2, 0);
      digitalWrite(INJ3, 0);
      digitalWrite(INJ4, 0);
      flag2 = 0;


  }
  
  if (digitalRead(OP1) == 1)
  {
    flag1 = 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("**Removendo Ar**");
    lcd.setCursor(0, 1);
    lcd.print("Iniciando......");
    digitalWrite(INJ1, 1);
    digitalWrite(DRENO1,1);
    digitalWrite(DRENO2,1);
    digitalWrite(DRENO3,1);
    digitalWrite(DRENO4,1);
    delay(1000);
    digitalWrite(INJ1, 0);
    digitalWrite(INJ2, 1);
    delay(1000);
    digitalWrite(INJ2, 0);
    digitalWrite(INJ3, 1);
    delay(1000);
    digitalWrite(INJ3, 0);
    digitalWrite(INJ4, 1);
    delay(1000);
    digitalWrite(INJ4, 0);
    digitalWrite(DRENO1,0);
    digitalWrite(DRENO2,0);
    digitalWrite(DRENO3,0);
    digitalWrite(DRENO4,0);
    lcd.clear();
	
    lcd.setCursor(0, 1);
    lcd.print("TEMPO(s): ");
    
    
    tempo2 = millis();
      while((millis() - tempo2) < tempototalestatico)
      {
        tensao = analogRead(sensor)*5.0/1023.0;
 		pressao1 = (tensao-1);//Equação da curva do sensor (Y= 0,4X + 1)
  		pressao = pressao1/0.4;
        lcd.setCursor(0, 0);
  		lcd.print("Press.:");
  		lcd.setCursor(7, 0);
  		lcd.print(pressao);
  		lcd.setCursor(13,0);
  		lcd.print("Bar");
        digitalWrite(INJ1, 1);
        digitalWrite(INJ2, 1);
        digitalWrite(INJ3, 1);
        digitalWrite(INJ4, 1);
        delay(tempoentrepulsos);
        lcd.setCursor(10, 1);
        int strr1 = (tempototalestatico-(millis() - tempo2))/1000;
        String strr2 = " ";
        String str1 =  strr1 + strr2;
        lcd.print(str1);
        if (digitalRead(OP1) && flag1 == 1)
        {
          break;
        }
        digitalWrite(INJ1, 0);
        digitalWrite(INJ2, 0);
        digitalWrite(INJ3, 0);
        digitalWrite(INJ4, 0);
      }
	  flag1=0;

  }
  
  if (flag1 == 0 && flag2 == 0)
  {
    lcd.clear();
  	lcd.setCursor(0, 0);
  	lcd.print("[1]Est. ou [2]Eq.");
    digitalWrite(INJ1, 0);
  	digitalWrite(INJ2, 0);
  	digitalWrite(INJ3, 0);
  	digitalWrite(INJ4, 0);
  	digitalWrite(DRENO1,0);
  	digitalWrite(DRENO2,0);
  	digitalWrite(DRENO3,0);
  	digitalWrite(DRENO4,0);
    lcd.setCursor(0, 1);
  	lcd.print("Press.:");
  	lcd.setCursor(7, 1);
  	lcd.print(pressao);
  	lcd.setCursor(13,1);
  	lcd.print("Bar");
  }
  delay(100);
}
