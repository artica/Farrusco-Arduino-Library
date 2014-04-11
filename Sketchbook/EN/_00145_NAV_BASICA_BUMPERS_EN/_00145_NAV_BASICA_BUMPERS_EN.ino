#include <Farrusco.h>

  Farrusco farrusco;

// --------------------------------------------------------------------------- BUMPERS
  int BLeft, BRight;

// --------------------------------------------------------------------------- MOTORES DC
  // calibration variables, use it to perform a straight path
  int maxSpeedLeft = 255;
  int maxSpeedRight = 210;

  int motorLeftSpeed = 255;
  int motorRightSpeed = 255;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP
void loop() 
{
    
  BLeft = farrusco.BLeftCheck();
  BRight = farrusco.BRightCheck();
  
  if (BLeft == 1) 
  {
    Beco(1);
  }
  else if (BRight == 1) 
  {
    Beco(2);
  }
  else 
  {
    // call 'DiffTurn' with motors speed
    farrusco.DiffTurn(motorLeftSpeed, motorRightSpeed);
  }  
}

