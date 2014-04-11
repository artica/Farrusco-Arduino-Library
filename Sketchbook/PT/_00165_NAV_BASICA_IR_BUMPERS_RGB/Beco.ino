void Beco(int beco) 
{  
  Serial.print("    Beco: ");
  Serial.println(beco);
  
  farrusco.ActuadorMotores(-maxVelocidadeEsq, -maxVelocidadeDir);
  delay(500);
  
  // se detectou obstáculo pela esquerda, vira para direita
  if (beco == 1)
    farrusco.ActuadorMotores(maxVelocidadeEsq, -maxVelocidadeDir);
  
  // se detectou obstáculo pela direita, vira para esquerda
  if (beco == 2)
    farrusco.ActuadorMotores(-maxVelocidadeEsq, maxVelocidadeDir);
  
  delay(250);
}
