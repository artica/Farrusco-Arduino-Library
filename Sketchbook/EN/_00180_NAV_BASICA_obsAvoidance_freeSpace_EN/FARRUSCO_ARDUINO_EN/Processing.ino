int numSaves = 0;

boolean ProcessingSerialReciever() 
{
  
  boolean result = false;
  
  if(Serial.available()>0)
  {
    //digitalWrite(13, HIGH);
    result = true;
    
    // call the returned value from GetFromSerial() function
    switch(GetFromSerial())
    {

    case 'Z':  // servo
      farrusco.WritePos(GetFromSerial());
      break;
    case 'P':  // pwm right
      //MotorSetMaxVelocity(GetFromSerial(), GetFromSerial());
       maxSpeedLeft = GetFromSerial();
       maxSpeedRight = GetFromSerial();
      break;
    case 'F':  // drive forward
      farrusco.DiffTurn(MAX_VELOCITY, MAX_VELOCITY);
      break;
    case 'B':   // drive backward
      farrusco.DiffTurn(-MAX_VELOCITY, -MAX_VELOCITY);
      break;
    case 'L':   // turn left
      farrusco.DiffTurn(-MAX_VELOCITY, MAX_VELOCITY);
      break;
    case 'R':  // turn right
      farrusco.DiffTurn(MAX_VELOCITY, -MAX_VELOCITY);
      break;
    case 'S':  // save on eeprom
      numSaves++;
      StoreEepromValues();
      break;
    case 'N':  // request state
      navState = GetFromSerial();
      break;
    case 'U':  // send serial data
      ProcessingSerialSender();
      break;

    default:   // H stop
      farrusco.DiffTurn(0,0);
      break;  
    }
  }
  
  return result;
}

// read the serial port
byte GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}

void ProcessingSerialSender() 
{
  Serial.print(BLeft, DEC);
  Serial.print(",");
  Serial.print(BRight, DEC);
  Serial.print(",");
  Serial.print(IRValue, DEC);
  Serial.print(",");
  Serial.print(navState, DEC);
  Serial.print(",");
  Serial.print(maxSpeedLeft, DEC);
  Serial.print(",");
  Serial.print(maxSpeedRight, DEC);
  Serial.print(",");
  Serial.print(numSaves, DEC);
  Serial.println();
  
}

unsigned long previousTime;
unsigned long processingStateTime = 4000;
boolean processingState = true;

int ProcessingUpdate() 
{
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > processingStateTime)
  {
    processingState = false;
    return processingState;
  }
  
  if (bumperMetro.check()) { 
   BLeft = farrusco.BLeftCheck();
   BRight = farrusco.BRightCheck();
  }

  if (sensorIRMetro.check()) { 
    IRValue = farrusco.IRValueCheck();
  }
  if(ProcessingSerialReciever()) {
    previousTime = currentTime;
    processingState = true;
  }
  
  return processingState;
  
}



