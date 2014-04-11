// --------------------------------------------------------------------------- SETUP
void obstacleAvoidanceSetup()
{
  checkDeadEndSetup();  
}

// --------------------------------------------------------------------------- UPDATE
int freeSpaceState = 0;
int freeSpaceLeft = 0;
int freeSpaceRight = 0;

void FreeSpaceUpdate() 
{

   paraChoquesEsq = farrusco.PChoqueEsqValor();
   paraChoquesDir = farrusco.PChoqueDirValor();
  
  if (sensorIVMetro.check() == 1) 
  { 
   IVValor = farrusco.IVValor();
  }
  
  if (servoMetro.check() == 1){ 

    farrusco.RotacaoValor(100,80,5);
  }
  // 1 = Pará choques esquerda // 2 = Pará choques direita // 0 = Nenhum pará choques foi pressionado
  if (!checkDeadEndUpdate())  // (checkDeadEnd() == 0)
  {  
    
    if (IVValor >= 300)   //estamos perto de um obstáculo
    {   
      farrusco.ActuadorMotores(maxVelocidadeEsq/4, maxVelocidadeDir/4);
      farrusco.RodaPosicao(150);
      delay(250);

      freeSpaceRight = farrusco.IVValor();
      farrusco.RodaPosicao(20);
      delay(250);

      freeSpaceLeft = farrusco.IVValor();
      
      if (freeSpaceLeft<freeSpaceRight)
        farrusco.ActuadorMotores(0, MAX_VELOCIDADE);
      else
       farrusco.ActuadorMotores(MAX_VELOCIDADE, 0);
      delay(250);
    }
    else// (IVValor < 299)
    {
        farrusco.ActuadorMotores(MAX_VELOCIDADE, MAX_VELOCIDADE);
        farrusco.RotacaoValor(120,50,5);
        farrusco.Espera(50);
        
     }
  }
}

// --------------------------------------------------------------------------- UPDATE
void ObstacleAvoidanceUpdate() 
{
   paraChoquesEsq = farrusco.PChoqueEsqValor();
   paraChoquesDir = farrusco.PChoqueDirValor();
 
   int servoPos = farrusco.ObterPosicao(); 
   
  if (sensorIVMetro.check() == 1) { 
    IVValor = farrusco.IVValor();
  }
  
  if (servoMetro.check() == 1) { 
    farrusco.Rotacao();
  }
  
  //imprime o valor do sensor de distância e a posição do servo
  Serial.print(IVValor);
  Serial.print("  ");
  Serial.println(servoPos);
  
  // 1 = Pará choques esquerdo // 2 = Pará choques direita // 0 = Nenhum pará choques foi pressionado
  if (!checkDeadEndUpdate())  // (checkDeadEnd() == 0)
  {  
   
    if (IVValor >= 300)   //estamos perto de um obstáculo
    {   
      if (servoPos < 90) 
      {
        farrusco.ActuadorMotores(MAX_VELOCIDADE, 0);
        farrusco.RotacaoValor(80, 20, 5);
        delay(250);
        
      }
      else //if (servoPos > 90) 
      {
       farrusco.ActuadorMotores(0, MAX_VELOCIDADE);
       farrusco.RotacaoValor(170, 110, 5);
       delay(250);
      }
    }
    else// (IVValor < 299)
    {
        farrusco.ActuadorMotores(MAX_VELOCIDADE, MAX_VELOCIDADE);
        farrusco.RotacaoValor(120, 50, 5); 
        delay(50);
        
     }
  }
}


