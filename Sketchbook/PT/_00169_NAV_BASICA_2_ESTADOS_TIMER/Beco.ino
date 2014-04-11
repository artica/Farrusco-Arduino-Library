void Beco(int from) 
{
  
  Serial.print("    Beco: ");
  Serial.println(from);
  
  digitalWrite(vermelho_pin, HIGH);
  digitalWrite(verde_pin, LOW);
  digitalWrite(azul_pin, LOW);
  
  farrusco.ActuadorMotores(-maxVelocidadeEsq, -maxVelocidadeDir);
  delay(250);
  
  // se detectou obstáculo pela esquerda, vira para direita
  if (from == 1)
     farrusco.ActuadorMotores(maxVelocidadeEsq, -maxVelocidadeDir);
  
  // se detectou obstáculo pela direita, vira para esquerda
  if (from == 2)
     farrusco.ActuadorMotores(-maxVelocidadeEsq, maxVelocidadeDir);
     delay(100);


}
