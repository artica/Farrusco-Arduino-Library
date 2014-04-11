#include <Farrusco.h>

Farrusco farrusco;

// --------------------------------------------------------------------------- MOTORES DC
// calibration variables, use it to perform a straight path
int maxSpeedLeft = 235;
int maxSpeedRight = 255;

int min_speed = 100;

int motorLeftSpeed, motorRightSpeed;

// --------------------------------------------------------------------------- SERVO
int servoPos;

// --------------------------------------------------------------------------- IR SENSOR
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
  
  IRValue = farrusco.IRValueCheck();
  Serial.print(IRValue);

  Serial.print("   ");
  servoPos = farrusco.GetPosition();
  Serial.println(servoPos);
  
  if (servoPos > 90){
    if (IRValue >= 300){ // we are near an obstacle
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;
      delay(250);
    }
    if(IRValue < 299){
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      delay(50);
    }
  }
  else if (servoPos < 90){
    if (IRValue >= 300){ //we are near an obstacle
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;
      delay(250);
    }
    if(IRValue < 299){
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      delay(50);
    }
  }
  
  // call 'DiffTurn' with motors speed
  farrusco.DiffTurn(motorLeftSpeed, motorRightSpeed);

}
