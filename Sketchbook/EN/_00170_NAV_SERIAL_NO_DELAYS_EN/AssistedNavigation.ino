void AssistedNavigation()
{
 BLeft = farrusco.BLeftCheck();
 BRight = farrusco.BRightCheck();
  
  if(!checkDeadEnd())
        SerialAnalyze(); 
}

int SerialAnalyze()
{
  //d
  if (inByte=='d' || inByte == 'D') // turns to right
  {
    farrusco.DiffTurn(maxSpeedLeft, -maxSpeedRight); 
  }
  //a
  else if(inByte=='a'|| inByte=='A') // turns to left
  {
    farrusco.DiffTurn(-maxSpeedLeft, maxSpeedRight);
  }
  //s
  else if(inByte=='s'|| inByte=='S') // go backward
  {
     farrusco.DiffTurn(-maxSpeedLeft, -maxSpeedRight);
  }
  //w
  else if(inByte=='w'|| inByte=='W') // go forward
  {
     farrusco.DiffTurn(maxSpeedLeft, maxSpeedRight);
  }
  //p
  else if(inByte=='p'|| inByte=='P' || inByte=='G' || inByte=='g') //stop
  {
    farrusco.DiffTurn(0, 0);
  }
}
