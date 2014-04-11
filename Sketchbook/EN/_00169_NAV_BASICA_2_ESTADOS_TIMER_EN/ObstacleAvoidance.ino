void ObstacleAvoidance() 
{
  farrusco.Range();

  IRValue = farrusco.IRValueCheck();

  BLeft = farrusco.BLeftCheck();  
  BRight = farrusco.BRightCheck();
  
  servoPos = farrusco.GetPosition();
 
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
    if (servoPos < 90){
      
      if (IRValue >= 300){ //we are near an obstacle
        
        digitalWrite(red_pin, LOW);
        digitalWrite(green_pin, HIGH);
        digitalWrite(blue_pin, LOW);
        
        motorRightSpeed = 0;
        motorLeftSpeed = maxSpeedLeft;      
        
        // slow down servo speed
        delay(250);
      }
      if(IRValue < 299){
        
        digitalWrite(red_pin, LOW);
        digitalWrite(green_pin, LOW);
        digitalWrite(blue_pin, HIGH);
        
        motorRightSpeed = maxSpeedRight;
        motorLeftSpeed = maxSpeedLeft;
        
        // speed up servo speed
        delay(50);
      }
    }
    
    // if 'servoPos' is over 90, the robot is facing right
    // to move away, the left motor is stopped
    // this way, only the right motor is spinning
    if (servoPos > 90){
      if (IRValue >= 300){ //we are near an obstacle
        
        digitalWrite(red_pin, LOW);
        digitalWrite(green_pin, HIGH);
        digitalWrite(blue_pin, LOW);
        
        motorRightSpeed = maxSpeedRight;
        motorLeftSpeed = 0;
  
        // slow down servo speed
       delay(250);
      }
      if(IRValue < 299){
        
        digitalWrite(red_pin, LOW);
        digitalWrite(green_pin, LOW);
        digitalWrite(blue_pin, HIGH);
        
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
