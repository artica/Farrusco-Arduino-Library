#include <Farrusco.h>

Farrusco farrusco;
// --------------------------------------------------------------------------- SERVO
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
//Distance Sensor
int IRValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
  
  farrusco.Range();
 
 //prints the value of the distance sensor
  IRValue = farrusco.IRValueCheck();
  Serial.print(IRValue);
  Serial.print("  ");

  BLeft = farrusco.BLeftCheck();  
  BRight = farrusco.BRightCheck();

  //prints the servo position
  servoPos = farrusco.GetPosition();
  Serial.println(servoPos);
 
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
  // if 'servoPos' is less than 90, the robot is facing left
  // to move away, the right motor is stopped
  // this way, only the left motor is spinning
 
   if (servoPos > 90) {
    if (IRValue >= 300){ // we are near an obstacle
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;

      // slow down servo speed
      delay(250);
    }
    if(IRValue < 299){
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      
      // speed up servo speed
    delay(50);
    }
  }
  
  // if 'servoPos' is over 90, the robot is facing right
  // to move away, the left motor is stopped
  // this way, only the right motor is spinning
  
  if (servoPos < 90) {
    if (IRValue >= 300){ //we are near an obstacle
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;

      // slow down servo speed
     delay(250);
    }
    if(IRValue < 299){
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      
      // speed up servo speed
     delay(50);
    }
  }
  
  //call 'DiffTurn' with motors speed
 farrusco.DiffTurn(motorLeftSpeed,motorRightSpeed);
  }  
}
