#include <FarruscoPT.h>

FarruscoPT farrusco;

// --------------------------------------------------------------------------- LDR
//Sensor de Luminosidade
int LDREsp_pin = 1;
int LDRDir_pin = 2;

int LDREsq;
int LDRDir;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq;
int pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
//Variáveis de calibração
int maxVelocidadeEsq = 235;
int maxVelocidadeDir = 255;

int minVelocidade = 150;

int velocidadeMotorEsq = 255;
int velocidadeMotorDir = 255;
// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP
void loop() 
{
  pChoquesEsq = farrusco.PChoqueEsqValor();
  pChoquesDir = farrusco.PChoqueDirValor();  

  if (pChoquesEsq == 1) 
  {
    Beco (1);
  }
  else if (pChoquesDir == 1) 
  {
    Beco (2);
  }
  else 
  {
   //imprime os valores dos sensores de luminosidade
    LDREsq = analogRead (LDREsp_pin);
    LDRDir = analogRead (LDRDir_pin);
    Serial.print(LDREsq);
    Serial.print("  ");
    Serial.println(LDRDir);
    
    //Farrusco procura a luz
    velocidadeMotorEsq = map (LDREsq, 0, 1023, minVelocidade, maxVelocidadeEsq);
    velocidadeMotorDir = map (LDRDir, 0, 1023, minVelocidade, maxVelocidadeDir);
    
    farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
    delay(10);
  }  
}

