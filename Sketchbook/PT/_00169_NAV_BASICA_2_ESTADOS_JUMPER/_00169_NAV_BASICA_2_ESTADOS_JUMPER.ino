#include <FarruscoPT.h>

/*

  Change state when a jumper is connected to pin 2
  
*/

FarruscoPT farrusco;
// --------------------------------------------------------------------------- JUMPER
//int jumperPin = 2;
int configPin = 2;

// --------------------------------------------------------------------------- LED 13

int ledPin =  13;    // o número do pin do LED  

int ledEstado = LOW;             // ledEstado used to set the LED

// --------------------------------------------------------------------------- ESTADO NAVEGAÇÃO

// 0 = obstacle avoidance
// 1 = follow light
int navEstado = 0;

// --------------------------------------------------------------------------- LDR
//Sensor de luminosidade
int LDREsq_pin = 1;
int LDRDir_pin = 2;

int LDREsq, LDRDir;

// --------------------------------------------------------------------------- LED RGB

int vermelho_pin = 19;
int verde_pin = 18;
int azul_pin = 17;

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq, pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
// Variáveis de Calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 210;

int minVelocidade = 100;

int velocidadeMotorEsq, velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
//sensor de distancia
int IvValor;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
    // CONFIG PIN
  pinMode(configPin, INPUT);
  // activa a resistência interna
  digitalWrite(configPin, HIGH);
  
  // led 13
  pinMode (ledPin, OUTPUT);

  // led rgb
  pinMode(vermelho_pin, OUTPUT);
  pinMode(verde_pin, OUTPUT);
  pinMode(azul_pin, OUTPUT);
    
  delay(1000);
}

void loop() 
{
  
  navEstado = digitalRead(configPin); 
  
  if (navEstado == 0) 
  {
    ObstacleAvoidance();
  }
  else 
  {
    FollowLight();
  }  
}

