#include <FarruscoPT.h>

/*  ----------------------------------------------------------------------------
 *  WWW.GUIBOT.PT                                                  WWW.ARTICA.CC
 *  ----------------------------------------------------------------------------
 *  FARRUSCO BASIC NAVIGATION
 *  ----------------------------------------------------------------------------
 *
 * Programa que Evita Obstaculos e testa funcionalidades basicas do Farrusco.
 * Os Delays foram removidos e agora usam-se intervalos de tempo com a biblioteca Metro,
 * isto possibilita a implementacao de computacao paralela.
 *
 *
 * This Obstacle Avoidance program tests Farrusco's basic features.  
 * Delays were removed and time intervals were added to perform parallel computing, 
 * Metro library is required. 
 *
 *
 *  Components                    Functions                Parameters
 *
 * - Motores                       ActuadorMotores()       maxVelocidadeEsq, maxVelocidadeDir
 * - Pará Choques                  PChoqueEsqValor()
 *                                 PChoqueDirValor()
 * - Sensor Infravermelho          IVValor()
 * - Servo                         RotacaoValor()          servoMax, servoMin, servoInc
 *                                 Espera()                servoDel
 *                                 ObterPosicao() 
 */                                  
                                   
FarruscoPT farrusco;
char val;

#define LED 13 // Define the led's pin
//Create a variable to hold the led's current estado
int estado = HIGH;

// --------------------------------------------------------------------------- METRO
#include <Metro.h>
Metro servoEsperaMetro = Metro(25);
Metro paraChoquesMetro = Metro(100); 
Metro sensorIVMetro = Metro(50); 
Metro becoMetro = Metro(500); 
Metro ledMetro = Metro (250);

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// incremento
int servoInc = 5;

// espera
int servoDel = 50;

int servoMin = 0;
int servoMax = 180;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq, pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
//Variáveis de calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 255;

int minVelocidade = 100;

int velocidadeMotorEsq, velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
int IvValor;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{
  HeartRate();
  
  obstacleAvoidanceUpdate();
}

