// --------------------------------------------------------------------------- BECO VARS

int becoEstado;
int para_Choques = 0; // 1 = esquerda, 2 = direita

void Beco(int estado) 
{
  if (estado == 0) 
  {
    farrusco.ActuadorMotores(-maxVelocidadeEsq, -maxVelocidadeDir);  
  }

  else if (estado == 1) 
  {
    if (para_Choques == 1) // pará choques esquerdo foi pressionado
     farrusco.ActuadorMotores(maxVelocidadeEsq, -maxVelocidadeDir);

    if (para_Choques == 2) // pará choques direito foi pressionado
      farrusco.ActuadorMotores(-maxVelocidadeEsq, maxVelocidadeDir);
  } 

  else if (estado == 2) 
  {
    para_Choques = 0;
    if(navAssistida == 1)
      inByte = 'p';
  }
}

// resolve dead end
int checkDeadEnd()  

{ // Verifica o estado dos pará choques
  if (pChoquesEsq == 1) 
  {
    becoEstado = 0;
    becoMetro.interval(500);
    becoMetro.reset();
    para_Choques = 1;
  }
  else if (pChoquesDir == 1) 
  { 
    becoEstado = 0;
    becoMetro.interval(500);
    becoMetro.reset();
    para_Choques = 2;
  }
  else if ( (para_Choques != 0) && (becoMetro.check() == 1))
  {
    // nenhum pará choques activo, o recuo foi bem sucedido - falta verificar os temporizadores para sair do beco
    // becoEstado = 0 - vira   // becoEstado = 1 - volta ao ínicio
    becoMetro.reset();
    if (becoEstado == 0) 
    { 
      becoMetro.reset();
      becoEstado++;
    }
    else if (becoEstado == 1)
    {
      becoEstado++;
    }
  }
  if (para_Choques!= 0) 
    Beco(becoEstado);
  return para_Choques;
}


