void FollowLight() 
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
  
   //prints the values of the light sensors
    LDRLeft = analogRead (LDRLeft_pin);
    Serial.print(LDRLeft);
    Serial.print("   ");
    
    LDRRight = analogRead (LDRRight_pin);
    Serial.println(LDRRight);
    // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
    motorLeftSpeed = map (LDRLeft, 0, 1023, 0, 255);
    motorRightSpeed = map (LDRRight, 0, 1023, 0, 255);
     
    // call 'DiffTurn' with motors speed
    farrusco.DiffTurn(motorLeftSpeed, motorRightSpeed);
  } 
}
