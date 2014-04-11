void Beco(int beco) 
{
  
  Serial.print("    Beco: ");
  Serial.println(beco);
  
  farrusco.ActuadorMotores(-maxVelocidadeEsq, -maxVelocidadeDir);
  delay(500);
  
  // se detectou obstáculo pela esquerda, vira p direita
  if (beco == 1)
   farrusco.ActuadorMotores(maxVelocidadeEsq, -maxVelocidadeDir);
   
  // se detectou pela direita, vira p esquerda
  if (beco == 2)
    farrusco.ActuadorMotores(-maxVelocidadeEsq, maxVelocidadeDir);
  
  delay(250);

  if (navEstado == 0) 
  {
    navEstado++;
  }
  else 
  {
    navEstado = 0;
  }
}
