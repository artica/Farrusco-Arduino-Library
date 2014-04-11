
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
 * - Motors                       DiffTurn()               MAX_VELOCITY, MAX_VELOCITY
 * - Bumpers                      BLeftCheck()
 *                                BRightCheck()    
 * - Infra-Red Sensor             IRValueCheck()
 * - Servo                        RangeValue()
 *                                WritePos()
 *                                Delay()
 *                                GetPosition()
*/
#include <EEPROM.h>
#include <Farrusco.h>


// navigation state
byte navState;

Farrusco farrusco;

// --------------------------------------------------------------------------- METRO
#include <Metro.h>
Metro servoMetro = Metro(25); 
Metro servoDelayMetro = Metro(25);
Metro bumperMetro = Metro(100); 
Metro sensorIRMetro = Metro(50); 
Metro serialMetro = Metro(50); 
Metro becoMetro = Metro(500); 

// --------------------------------------------------------------------------- BUMPERS
int BLeft, BRight;

// --------------------------------------------------------------------------- IR SENSOR
//distance sensor
int IRValue;

// --------------------------------------------------------------------------- MOTORES
int min_speed = 100;

const int MAX_VELOCITY = 255;

// calibration variables, use it to perform a straight path
byte maxSpeedLeft = 255;
byte maxSpeedRight = 255;
// --------------------------------------------------------------------------- SETUP

void ReadEepromValues()
{
  navState = EEPROM.read(0);
  maxSpeedLeft = EEPROM.read(1);
  maxSpeedRight = EEPROM.read(2); 
}

void StoreEepromValues()
{
  EEPROM.write(0,navState);
  EEPROM.write(1,maxSpeedLeft);
  EEPROM.write(2,maxSpeedRight);
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
    switch(navState)
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

