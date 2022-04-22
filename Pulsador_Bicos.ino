#include <LiquidCrystal.h>

#define INJ1 31
#define INJ2 35
#define INJ3 39
#define INJ4 43

#define UP 22
#define LEFT 26
#define RIGHT 30
#define DOWN 34
#define ENTER 38


//////////////////////////Pinos Display//////////////////////////////
#define pinRs 8
#define pinEn 9
#define pinD4 4
#define pinD5 5
#define pinD6 6
#define pinD7 7
#define pinBackLight 10
LiquidCrystal lcd(pinRs, pinEn, pinD4, pinD5, pinD6, pinD7);
////////////////////////////////////////////////////////////////////

unsigned long tempototal = 120000;
unsigned long tempo2 = 0;
unsigned long tempoentrepulsos = 60;

int flagenter = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(INJ1, OUTPUT);
  pinMode(INJ2, OUTPUT);
  pinMode(INJ3, OUTPUT);
  pinMode(INJ4, OUTPUT);
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(ENTER, INPUT);
  pinMode(pinBackLight, OUTPUT);
  digitalWrite(pinBackLight, HIGH);

  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Diego G Land");
  lcd.setCursor(0, 1);
  lcd.print(" Pulsador_Bicos ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" RS Performance");
  lcd.setCursor(0, 1);
  lcd.print("Press. uma tecla");

}


void loop()
{
  if (digitalRead(ENTER) == 1)
  {
    digitalWrite(INJ1, 0);
    digitalWrite(INJ2, 0);
    digitalWrite(INJ3, 0);
    digitalWrite(INJ4, 0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(">>>>PULSANDO<<<<");
    lcd.setCursor(0, 1);
    lcd.print("TEMPO(s): ");
    
    
    tempo2 = millis();
      while((millis() - tempo2) < tempototal)
      {
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
        lcd.setCursor(9, 1);
        lcd.print( tempototal/1000);
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" RS Performance");
      lcd.setCursor(0, 1);
      lcd.print("Press. uma tecla");

  }
  if (digitalRead(LEFT) == 1)
  {
      digitalWrite(INJ1, 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Injetor 1: ");
      lcd.setCursor(0, 1);
      lcd.print(" ABERTO ");
  }
  if (digitalRead(RIGHT) == 1)
  {
      digitalWrite(INJ2, 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Injetor 2: ");
      lcd.setCursor(0, 1);
      lcd.print(" ABERTO ");
  }
  if (digitalRead(UP) == 1)
  {
      digitalWrite(INJ3, 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Injetor 3: ");
      lcd.setCursor(0, 1);
      lcd.print(" ABERTO ");
  }
  if (digitalRead(DOWN) == 1)
  {
      digitalWrite(INJ4, 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Injetor 4: ");
      lcd.setCursor(0, 1);
      lcd.print(" ABERTO ");
  }
}
