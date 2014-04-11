#include <FarruscoPT.h>

  FarruscoPT farrusco;

// --------------------------------------------------------------------------- BUMPERS
  int pChoqueEsq;
  int pChoqueDir;

// --------------------------------------------------------------------------- MOTORES DC
   //Variáveis de calibração
  int maxVelocidadeEsq = 255;
  int maxVelocidadeDir = 210;

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
    
  pChoqueEsq = farrusco.PChoqueEsqValor();
  pChoqueDir = farrusco.PChoqueDirValor();
  
  if (pChoqueEsq == 1) 
  {
    Beco(1);
  }
  else if (pChoqueDir == 1) 
  {
    Beco(2);
  }
  else 
  {
    // chamar 'ActuadorMotores' com a velocidade dos motores
    farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  }  
}

