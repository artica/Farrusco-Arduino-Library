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

// --------------------------------------------------------------------------- LED RGB
int red_pin = 19;
int green_pin = 18;
int blue_pin = 17;

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
int IRValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);

  // led rgb
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  
  delay(1000);
}

void loop() 
{
  Serial.println(nav_state);
  if (nav_state == 0) 
  {
    ObstacleAvoidance();
  }
  else 
  {
    FollowLight();
  }
  
}

