#include <FarruscoPT.h>

FarruscoPT farrusco;

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
 * - Pará Choques                 PChoqueEsqValor()   
 *                                PChoqueDirValor()
 * - Motores                      ActuadorMotores()        maxVelocidadeEsq, maxVelocidadeDir
 * - Sensor Infra-Vermelho        IVValor()                       
 * - Servo                        RotacaoValor()           servoMax, servoMin, servoInc         
 *                                Espera()                 servoDel
 *                                ObterPosicao() 
*/

char val;

#define LED 13 // pin do LED
//Variável que indica o estado do LED
int estado = HIGH;

// --------------------------------------------------------------------------- METRO
#include <Metro.h>
Metro servoEsperaMetro = Metro(25);
Metro paraChoquesMetro = Metro(100); 
Metro sensorIVMetro = Metro(50); 
Metro serialMetro = Metro(50); 
Metro becoMetro = Metro(500); 
Metro ledMetro = Metro (250);

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// incremento do servo
int servoInc = 5;

// tempo de espera
int servoDel = 50;

int servoMin = 0;
int servoMax = 180;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq, pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
// variáveis de calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 255;
int inByte = 'p'; 
char ordem = '1'; //Váriavel que define o estado da navegação. 1 - Navegação Assistida  2 -Evitar Obstáculos
int navAssistida = 1;
int minVelocidade = 100;

int velocidadeMotorEsq, velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
//Sensor de distância
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
  
  if (Serial.available() > 0) 
  {
    inByte = Serial.read();
    if(inByte == '1') 
      ordem = inByte;
    if(inByte == '2') 
      ordem = inByte;
  }
    if(ordem == '1')
   { 
     navAssistida = 1;
      Serial.println("assistentedenavegacao");
      AssistedNavigation();
   }
    else if(ordem == '2') 
    {
      Serial.println("obstaculo");
      navAssistida = 0;
      obstacleAvoidanceUpdate();
    }

}

