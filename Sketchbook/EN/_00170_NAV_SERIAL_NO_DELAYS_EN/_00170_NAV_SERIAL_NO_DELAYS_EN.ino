#include <Farrusco.h>

Farrusco farrusco;

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
 * - Bumpers                       BLeftCheck()             
 *                                 BRightCheck()
 * - Motors                        DiffTurn()              maxSpeedLeft, maxSpeedRight
 * - Infra-Red Sensor              IRValueCheck()
 * - Servo                         RangeValue()            servoMax, servoMin, servoInc
 *                                 Delay()                 servoDel
 *                                 GetPosition()
*/

char val;

#define LED 13 // Define the led's pin
//Create a variable to hold theled's current state
int state = HIGH;

// --------------------------------------------------------------------------- METRO
#include <Metro.h>
Metro servoDelayMetro = Metro(25);
Metro bumperMetro = Metro(100); 
Metro sensorIRMetro = Metro(50); 
Metro serialMetro = Metro(50); 
Metro becoMetro = Metro(500); 
Metro ledMetro = Metro (250);

// --------------------------------------------------------------------------- SERVO
// value to be sent to the servo
int servoPos = 90;

// increment
int servoInc = 5;

// delay
int servoDel = 50;

int servoMin = 0;
int servoMax = 180;

// --------------------------------------------------------------------------- BUMPERS
int BLeft, BRight;

// --------------------------------------------------------------------------- MOTORES DC
// calibration variables, use it to perform a straight path
int maxSpeedLeft = 255;
int maxSpeedRight = 255;
int inByte = 'p';
char order = '1'; // Defines the state of navigation. 1 - Assisted Navigation 2 - Obstacle Avoidance
int isAssitedNavigation = 1;
int minSpeed = 100;

int motorLeftSpeed, motorRightSpeed;

// --------------------------------------------------------------------------- IR SENSOR
//distance Sensor
int IRValue;

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
      order = inByte;
    if(inByte == '2') 
      order = inByte;
  }
    if(order == '1')
   { 
     isAssitedNavigation = 1;
   Serial.println("assistentedenavegacao");
      AssistedNavigation();
   }
    else if(order == '2') 
    {
      Serial.println("obstaculo");
      isAssitedNavigation = 0;
      obstacleAvoidanceUpdate();
    }

}
