#include <Farrusco.h>

Farrusco farrusco;
// --------------------------------------------------------------------------- NAVIGATION STATE

// 0 = obstacle avoidance
// 1 = follow light
int nav_state = 0;

// --------------------------------------------------------------------------- LDR
int LDRLeft_pin = 1;
int LDRRight_pin = 2;

int LDRLeft, LDRRight;


// --------------------------------------------------------------------------- SERVO
// value to be sent to the servo
int servoPos = 90;
// --------------------------------------------------------------------------- BUMPERS

int BLeft, BRight;

// --------------------------------------------------------------------------- MOTORES DC
// calibration variables, use it to perform a straight path
int maxSpeedLeft = 255;
int maxSpeedRight = 210;

int min_speed = 100;

int motorLeftSpeed, motorRightSpeed;

// --------------------------------------------------------------------------- IR SENSOR
//distance Sensor
int IRValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{  
  if (nav_state == 0) 
  {
    FollowLine();
  }
  else 
  {
    ObstacleAvoidance();   
  } 
}

