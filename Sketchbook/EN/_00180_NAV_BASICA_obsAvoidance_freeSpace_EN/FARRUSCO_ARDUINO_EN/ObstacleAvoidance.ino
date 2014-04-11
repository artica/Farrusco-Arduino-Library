// --------------------------------------------------------------------------- SETUP
void obstacleAvoidanceSetup()
{
  checkDeadEndSetup();  
}
//------------------------------------------------------------------------- UPDATE
int freeSpaceState = 0;
int freeSpaceLeft = 0;
int freeSpaceRight = 0;

void FreeSpaceUpdate() 
{
   BLeft = farrusco.BLeftCheck();
   BRight = farrusco.BRightCheck();
  
  if (sensorIRMetro.check() == 1) 
  { 
   IRValue = farrusco.IRValueCheck();
  }
  
  if (servoMetro.check() == 1){ 
    farrusco.RangeValue(100,80,5);
  }
  
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEndUpdate())  // (checkDeadEnd() == 0)
  {  

    if (IRValue >= 300)   // we are near an obstacle
    {   
      farrusco.DiffTurn(maxSpeedLeft/4, maxSpeedRight/4);
      farrusco.WritePos(150);
      delay(250);
      
      freeSpaceRight = farrusco.IRValueCheck();
      farrusco.WritePos(20);
      delay(250);

      freeSpaceLeft = farrusco.IRValueCheck();
      
      if (freeSpaceLeft<freeSpaceRight)
        farrusco.DiffTurn(0, MAX_VELOCITY);
      else
       farrusco.DiffTurn(MAX_VELOCITY, 0);
      delay(250);
    }
    else// (IRValue < 299)
    {
        farrusco.DiffTurn(MAX_VELOCITY, MAX_VELOCITY);
        farrusco.RangeValue(120,50,5);
        farrusco.Delay(50);
        
     }
  }
}

// --------------------------------------------------------------------------- UPDATE
void ObstacleAvoidanceUpdate() 
{
   BLeft = farrusco.BLeftCheck();
   BRight = farrusco.BRightCheck();
 
   int servoPos = farrusco.GetPosition(); 
   
  if (sensorIRMetro.check() == 1) { 
    IRValue = farrusco.IRValueCheck();
  }
  
  if (servoMetro.check() == 1) { 
    farrusco.Range();
  }
  
  // prints the value of the distance sensor and the servo position
  Serial.print(IRValue);
  Serial.print("  ");
  Serial.println(servoPos);
  
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEndUpdate())  // (checkDeadEnd() == 0)
  {  
    if (IRValue >= 300)   //we are near an obstacle
    {   
      if (servoPos < 90) 
      {
        farrusco.DiffTurn(MAX_VELOCITY, 0);
        farrusco.RangeValue(80, 20, 5); 
        delay(250);        
      }
      else //if (servoPos > 90) 
      {
       farrusco.DiffTurn(0, MAX_VELOCITY);
       farrusco.RangeValue(170, 110, 5);
       delay(250);
      }
    }
    else// (IRValue < 299)
    {
        farrusco.DiffTurn(MAX_VELOCITY, MAX_VELOCITY);
        farrusco.RangeValue(120, 50, 5); 
        delay(50);
     }
  }
}


