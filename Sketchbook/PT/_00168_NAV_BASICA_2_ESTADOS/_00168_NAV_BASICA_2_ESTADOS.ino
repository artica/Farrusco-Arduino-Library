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

int LDREsq;
int LDRDir;

// --------------------------------------------------------------------------- LED RGB
int vermelho_pin = 19;
int verde_pin = 18;
int azul_pin = 17;

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq;
int pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
//Variáveis de Calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 210;

int minVelocidade = 100;

int velocidadeMotorEsq;
int velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
//sensor de distância
int IvValor;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);

  // led rgb
  pinMode(vermelho_pin, OUTPUT);
  pinMode(verde_pin, OUTPUT);
  pinMode(azul_pin, OUTPUT);
  
  delay(1000);
}

void loop() 
{
  //imprime qual o estado da navegação
  Serial.print("navEstado:");
  Serial.println(navEstado);
  if (navEstado == 0) 
  {
    ObstacleAvoidance();
  }
  else 
  {
    FollowLight();
  }
  
}

