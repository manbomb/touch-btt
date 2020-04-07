int pinBtt = 18;
int pinoVerde = 5;
int pinoTouchOn = 4;
int capacitanciaMaxima = 30;
 
void setup()
{
   Serial.begin(115200);
   delay(1000);
   pinMode(pinoVerde, OUTPUT);
   pinMode(pinBtt, INPUT_PULLUP);
}

void loop()
{
  Serial.print("Valor: ");
  Serial.println(touchRead(pinoTouchOn));
  bool toggle = false;
  
  if(digitalRead(pinBtt) == HIGH) {
    toggle = true;
  }
  
  Serial.print("Toggle: ");
  Serial.println(toggle);
  
  int media = 0;

  for(int i=0; i< 100; i++)
  {
    media += touchRead(pinoTouchOn);
  }
   
  media = media / 100;
 
  if(media < capacitanciaMaxima && !toggle)
  {
    digitalWrite(pinoVerde, !digitalRead(pinoVerde));
    while(media < capacitanciaMaxima) { 
      delay(10);
      
      int soma = 0;

      for(int i=0; i< 100; i++)
      {
        soma += touchRead(pinoTouchOn);
      }
       
      media = soma / 100;
    }
  }
  
  if(media < capacitanciaMaxima && toggle)
  {
    digitalWrite(pinoVerde, HIGH);
    while(media < capacitanciaMaxima) {
      delay(10);
      
      int soma = 0;

      for(int i=0; i< 100; i++)
      {
        soma += touchRead(pinoTouchOn);
      }
       
      media = soma / 100;
    }
    digitalWrite(pinoVerde, LOW);
  } 
  
  delay(10);
}
