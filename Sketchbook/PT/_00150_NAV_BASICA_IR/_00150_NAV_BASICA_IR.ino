#include <FarruscoPT.h>

FarruscoPT farrusco;

// --------------------------------------------------------------------------- MOTORES DC
//Variáveis de Calibracao
int maxVelocidadeEsq = 235;
int maxVelocidadeDir = 255;

int minVelocidade = 100;

int VelocidadeMotorEsq;
int VelocidadeMotorDir;

// --------------------------------------------------------------------------- SERVO
int servoPos;

// --------------------------------------------------------------------------- IV SENSOR
//Sensor de distância
int IvValor;
// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
  farrusco.Rotacao();
  
  IvValor = farrusco.IVValor();
  Serial.print(IvValor);

  Serial.print("   ");
  servoPos = farrusco.ObterPosicao();
  Serial.println(servoPos);
  
  if (servoPos > 90){
    if (IvValor >= 300){ //estamos perto de um obstáculo
      VelocidadeMotorDir = maxVelocidadeDir;
      VelocidadeMotorEsq = 0;
      delay(250);
    }
    if(IvValor < 299){
      VelocidadeMotorDir = maxVelocidadeDir;
      VelocidadeMotorEsq = maxVelocidadeEsq;
      delay(50);
    }
  }
  else if (servoPos < 90){
    if (IvValor >= 300){ //estamos perto de um obstáculo
      VelocidadeMotorDir = 0;
      VelocidadeMotorEsq = maxVelocidadeEsq;
      delay(250);
    }
    if(IvValor < 299){
      VelocidadeMotorDir = maxVelocidadeDir;
      VelocidadeMotorEsq = maxVelocidadeEsq;
     delay(50);
    }
  }
  
  // chamada da função 'ActuadorMotores' atribuindo sempre os valores de rotação dos motores
  farrusco.ActuadorMotores(VelocidadeMotorEsq, VelocidadeMotorDir);
 
}

