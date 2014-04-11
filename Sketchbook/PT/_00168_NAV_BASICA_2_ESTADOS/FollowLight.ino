void FollowLight() 
{
    pChoquesEsq = farrusco.PChoqueEsqValor();  
    pChoquesDir = farrusco.PChoqueDirValor();
   
  if (pChoquesEsq == 1) 
  {
    Beco (1);
  }
  else if (pChoquesDir == 1) 
  {
    Beco (2);
  }
  else 
  {
    //imprime no ecra os valores dos sensores de luminosidade
    LDREsq = analogRead (LDREsq_pin);
    Serial.print(LDREsq);
    Serial.print("   "); 
    LDRDir = analogRead (LDRDir_pin);
    Serial.println(LDRDir);
    
    // Farrusco procura a luz 
    velocidadeMotorEsq = map (LDREsq, 0, 1023, 0, 255);
    velocidadeMotorDir = map (LDRDir, 0, 1023, 0, 255);
    
    farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  } 
}
