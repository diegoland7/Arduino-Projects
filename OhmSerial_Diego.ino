
float analog, calc, media;
int amostra1 = 0, amostra2, amostra3, amostra4, amostra5, result;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  char leitura = Serial.read();

    for (int i = 0; i <= 5; i++)
    {
      analog = analogRead(0);
      calc = float (analog*5/1024);
      amostra1 = float (990*(5-calc)/calc);
      amostra = amostra + amostra1;
      delay(50);
    }
 
    media = ((amostra1+amostra2+amostra3+amostra4+amostra5)/5);

    Serial.print(media);
    Serial.print(" Ohm \n");
  }
}
