void AssistedNavigation()
{
 pChoquesEsq = farrusco.PChoqueEsqValor();
 pChoquesDir = farrusco.PChoqueDirValor();
  
  if(!checkDeadEnd())
        SerialAnalyze(); 
}

int SerialAnalyze()
{
  //d
  if (inByte == 'd' || inByte == 'D') // vira para a direita
  {
    farrusco.ActuadorMotores(maxVelocidadeEsq, -maxVelocidadeDir); 
  }
  //a
  else if(inByte == 'a'|| inByte == 'A') // vira para a esquerda
  {
    farrusco.ActuadorMotores(-maxVelocidadeEsq, maxVelocidadeDir);
  }
  //s
  else if(inByte == 's'|| inByte == 'S')// recua
  {
     farrusco.ActuadorMotores(-maxVelocidadeEsq, -maxVelocidadeDir);
  }
  //w
  else if(inByte == 'w'|| inByte == 'W')// avança
  {
     farrusco.ActuadorMotores(maxVelocidadeEsq, maxVelocidadeDir);
  }
  //p
  else if(inByte == 'p'|| inByte == 'P' || inByte == 'G' || inByte == 'g') //pará
  {
    farrusco.ActuadorMotores(0, 0);
  }
}
