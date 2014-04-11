#include <FarruscoPT.h>

FarruscoPT farrusco;
// --------------------------------------------------------------------------- ESTADO NAVEGAÇÃO

// 0 = obstacle avoidance
// 1 = follow light
int navEstado = 0;

// --------------------------------------------------------------------------- LDR
//Sensor de luminosidade
int LDREsq_pin = 1;
int LDRDir_pin = 2;

int LDREsq, LDRDir;

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// --------------------------------------------------------------------------- PARÁ CHOQUES

int pChoquesEsq, pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
// Variáveis de calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 210;

int minVelocidade = 100;

int velocidadeMotorEsq, velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
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
  if (navEstado == 0) 
  {
    FollowLine();
  }
  else 
  {
    ObstacleAvoidance();   
  } 
}

