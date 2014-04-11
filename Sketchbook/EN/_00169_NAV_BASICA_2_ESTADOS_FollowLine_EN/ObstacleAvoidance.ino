void ObstacleAvoidance() 
{

  farrusco.Range();
  
  IRValue = farrusco.IRValueCheck();

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
  // if 'servoPos' is less than 90, the robot is facing left
  // to move away, the right motor is stopped
  // this way, only the left motor is spinning
  if (servoPos < 90) {
    
    if (IRValue >= 300)   {
      motorLeftSpeed = maxSpeedLeft;
      motorRightSpeed = 0;

      // slow down servo speed
      delay(250);
    }
    if(IRValue < 299) {
      
      motorLeftSpeed = maxSpeedLeft;
      motorRightSpeed = maxSpeedRight;
      
      // speed up servo speed
      delay(50);
    }
  }
  
  // if 'servoPos' is over 90, the robot is facing right
  // to move away, the left motor is stopped
  // this way, only the right motor is spinning
  if (servoPos > 90) {
    if (IRValue >= 300) {
      motorLeftSpeed = 0;

      // slow down servo speed
      delay(250);
    }
    if(IRValue < 299) {
      
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
