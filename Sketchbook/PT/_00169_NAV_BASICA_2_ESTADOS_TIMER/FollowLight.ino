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
  //lê o valor dos sensores de luminosidade
  LDRDir = analogRead (LDREsq_pin);
  LDREsq = analogRead (LDRDir_pin);
  
  //Farrusco procura a luz
  velocidadeMotorEsq = map (LDREsq, 0, 1023, 0, 255);
  velocidadeMotorDir = map (LDRDir, 0, 1023, 0, 255);
  
  farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  } 
}
