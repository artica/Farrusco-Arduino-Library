// --------------------------------------------------------------------------- BECO VARS

int becoEstado;
int para_choques = 0; // 1 = esquerda, 2 = direita


// --------------------------------------------------------------------------- BECO
void Beco(int estado) 
{
  if (estado == 0) 
  {
    farrusco.ActuadorMotores(-MAX_VELOCIDADE, -MAX_VELOCIDADE);
  }
  else if (estado == 1) 
  {
    if (para_choques == 1) // pará choques da esquerda pressionado
      farrusco.ActuadorMotores(MAX_VELOCIDADE, -MAX_VELOCIDADE);

    if (para_choques == 2) // pará choques da direita pressionado
      farrusco.ActuadorMotores(-MAX_VELOCIDADE, MAX_VELOCIDADE);
  } 
  else if (estado == 2) 
  {
    para_choques = 0;
  }
}


// --------------------------------------------------------------------------- BECO SETUP
void checkDeadEndSetup()
{
  becoEstado = 2;
  para_choques = 0;
}

// --------------------------------------------------------------------------- BECO UPDATE
/* 
  returns 'para_choques': 
   1 se o pará choques da esquerda foi activado
   2 se o pará choques da direita foi activado
   0 dead end solved
*/
// resolves dead end
int checkDeadEndUpdate()  

{ // Verifica o estado dos pará choques
  if (paraChoquesEsq == 1) 
  {
    becoEstado = 0;
    becoMetro.interval(500);
    becoMetro.reset();
    para_choques = 1;
  }
  else if (paraChoquesDir == 1) 
  { 
    becoEstado = 0;
    becoMetro.interval(500);
    becoMetro.reset();
    para_choques = 2;
  }
  else if ( (para_choques != 0) && (becoMetro.check() == 1))
  {
    // nenhum pará choques activo, o recuo foi bem sucedido - falta verificar os temporizadores para sair do beco
    // becoEstado = 0 - virar    // becoEstado = 1 - volta ao ínicio
    if (becoEstado == 0) 
    {
      becoMetro.interval(500); 
      becoEstado++;
    }
    else if (becoEstado == 1)
    {
      becoEstado++;
    }
  }
  if (para_choques!=0) 
    Beco(becoEstado);
  return para_choques;
}


