void Beco(int from) 
{
  
  Serial.print("    Beco: ");
  Serial.println(from);
  
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, LOW);
  digitalWrite(blue_pin, LOW);
  
  farrusco.DiffTurn(-maxSpeedLeft, -maxSpeedRight);
  delay(250);
  
  // if an obstacle is detected on the left, the robot turns to the right
  if (from == 1)
     farrusco.DiffTurn(maxSpeedLeft, -maxSpeedRight);
  
  //if an obstacle is detected on the right, the robot turns to the left
  if (from == 2)
     farrusco.DiffTurn(-maxSpeedLeft, maxSpeedRight);
     delay(100);


}
