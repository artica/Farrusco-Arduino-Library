
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
 * - Motores                      ActuadorMotores()        MAX_VELOCIDADE, MAX_VELOCIDADE
 * - Bumpers                      PChoqueEsqValor()
 *                                PChoqueDirValor()
 * - Sensor Infra-Vermelho        IVValor()    
 * - Servo                        RotacaoValor()                                              
 *                                RodaPosicao()
 *                                Espera()
*/
#include <EEPROM.h>
#include <FarruscoPT.h>

// navegação estado
byte navEstado;

//const int MAX_VELOCIDADE = 255;

FarruscoPT farrusco;

// --------------------------------------------------------------------------- METRO
#include <Metro.h>;
Metro servoMetro = Metro(25); 
Metro servoEsperaMetro = Metro(25);
Metro paraChoquesMetro = Metro(100); 
Metro sensorIVMetro = Metro(50); 
Metro serialMetro = Metro(50); 
Metro becoMetro = Metro(500); 

// --------------------------------------------------------------------------- PARÁ CHOQUES
int paraChoquesEsq, paraChoquesDir;

// --------------------------------------------------------------------------- IR SENSOR
//sensor de distancia
int IVValor;

// --------------------------------------------------------------------------- MOTORES
byte maxVelocidadeEsq = 255;
byte maxVelocidadeDir = 255;

int minVelocidade = 100;

const int MAX_VELOCIDADE = 255;

// --------------------------------------------------------------------------- SETUP

void ReadEepromValues()
{
  navEstado = EEPROM.read(0);
  maxVelocidadeEsq = EEPROM.read(1);
  maxVelocidadeDir = EEPROM.read(2);
}

void StoreEepromValues()
{
  EEPROM.write(0,navEstado);
  EEPROM.write(1,maxVelocidadeEsq);
  EEPROM.write(2,maxVelocidadeDir);
}

void setup() 
{
  Serial.begin(115200);
  
  ReadEepromValues();

  HeartBitSetup();
  obstacleAvoidanceSetup();
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{

  HeartBit();
  
  if (!ProcessingUpdate()) {
    switch(navEstado)
    {
      case 0:
        Serial.println("EvitarObstaculo");
        ObstacleAvoidanceUpdate();
        break;
      case 1: 
        Serial.println("FreeSpace");
        FreeSpaceUpdate();
        break;
    } 
  }
}

