#include <Farrusco.h>

Farrusco farrusco;

// --------------------------------------------------------------------------- LDR
//Light Sensor
int LDRLeft_pin = 1;
int LDRRight_pin = 2;

int LDRLeft, LDRRight;

// --------------------------------------------------------------------------- BUMPERS

int BLeft, BRight;

// --------------------------------------------------------------------------- MOTORES DC

// calibration variables, use it to perform a straight path
int maxSpeedLeft = 235;
int maxSpeedRight = 255;

int min_speed = 150;

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
    Beco (1);
  }
  else if (BRight == 1) 
  {
    Beco (2);
  }
  else 
  {
    //prints the values of light sensors
    LDRLeft = analogRead (LDRLeft_pin);
    LDRRight = analogRead (LDRRight_pin);
    Serial.print(LDRLeft);
    Serial.print("  ");
    Serial.println(LDRRight);
    
    // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
    motorLeftSpeed = map (LDRLeft, 0, 1023, min_speed, maxSpeedLeft);
    motorRightSpeed = map (LDRRight, 0, 1023, min_speed, maxSpeedRight);
    
    // call 'DiffTurn' with motors speed
    farrusco.DiffTurn(motorLeftSpeed, motorRightSpeed);
    delay(10);
  }  
}
