

// --------------------------------------------------------------------------- UPDATE

void obstacleAvoidanceUpdate() 
{

 BLeft = farrusco.BLeftCheck();
 BRight = farrusco.BRightCheck();
  
  if (sensorIRMetro.check() == 1) { 
    IRValue = farrusco.IRValueCheck();
    sensorIRMetro.reset();
  }
  
  farrusco.RangeValue(servoMax, servoMin, servoInc);
  farrusco.Delay(servoDel);
  
  servoPos = farrusco.GetPosition();
  
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEnd())  // THE SAME AS (checkDeadEnd() == 0)
  {  
    motorRightSpeed = maxSpeedRight;
    motorLeftSpeed = maxSpeedLeft;
    
    // speed up servo speed and maximize range
    servoDel = 45;
    servoMin = 20;
    servoMax = 160;
   
    if (IRValue >= 300)   //we are near an obstacle
    {   
      if (servoPos < 90) 
      {
        Serial.println("if (servoPos < 90)");
        motorRightSpeed = 0;
        
        // slow down servo speed and constrain range
        servoDel = 250;
        servoMin = 20;
        servoMax = 80;
      }
      else //if (servoPos > 90) 
      {
        Serial.println("if (servoPos > 90)");
        motorLeftSpeed = 0;
        
        // slow down servo speed and constrain range
        servoDel = 250;
        servoMin = 110;
        servoMax = 160;
      }
    }

    //call 'DiffTurn' with motors speed
    farrusco.DiffTurn(motorLeftSpeed,motorRightSpeed);
  }
}


