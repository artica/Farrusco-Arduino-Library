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
    digitalWrite(vermelho_pin, LOW);
    digitalWrite(verde_pin, LOW);
    digitalWrite(azul_pin, HIGH);
    
  //leitura dos sensores de luminosidade
  LDRDir = analogRead (LDREsq_pin);
  LDREsq = analogRead (LDRDir_pin);
  
  //Imprime o valor dos sensores de luninosidade 
  Serial.print(LDREsq);
  Serial.print("   ");
  Serial.println(LDRDir);
  
  //Farrusco procura a luz
  velocidadeMotorEsq = map (LDREsq, 0, 1023, 0, 255);
  velocidadeMotorDir = map (LDRDir, 0, 1023, 0, 255);
  
  farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  } 
}
