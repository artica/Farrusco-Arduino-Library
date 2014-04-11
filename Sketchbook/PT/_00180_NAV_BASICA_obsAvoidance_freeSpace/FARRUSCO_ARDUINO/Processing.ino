int numSaves = 0;

boolean ProcessingSerialReciever() 
{
  
  boolean resultado = false;
  
  if(Serial.available()>0)
  {
    //digitalWrite(13, HIGH);
    resultado = true;
    
    // Chama o valor retornado pela função GetFromSerial
    switch(GetFromSerial())
    {

    case 'Z':  // servo
      farrusco.RodaPosicao(GetFromSerial());
      break;
    case 'P':  // pwm direita
       maxVelocidadeEsq = GetFromSerial();
       maxVelocidadeDir = GetFromSerial(); 
      break;
    case 'F':  // Avança
      farrusco.ActuadorMotores(MAX_VELOCIDADE, MAX_VELOCIDADE);
      break;
    case 'B':   // Recua
      farrusco.ActuadorMotores(-MAX_VELOCIDADE, -MAX_VELOCIDADE);
      break;
    case 'L':   // Vira à esquerda
      farrusco.ActuadorMotores(-MAX_VELOCIDADE, MAX_VELOCIDADE);
      break;
    case 'R':  // Vira à direita
      farrusco.ActuadorMotores(MAX_VELOCIDADE, -MAX_VELOCIDADE);
      break;
    case 'S':  // Guarda na eeprom
      numSaves++;
      StoreEepromValues();
      break;
    case 'N':  // Verifica o estado da navegação
      navEstado = GetFromSerial();
      break;
    case 'U':  // envia serial data
      ProcessingSerialSender();
      break;
      

    default:   // H pará
      farrusco.ActuadorMotores(0,0);
      break;  
    }
  }
  
  return resultado;
}

// lê a porta Serie
byte GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}

void ProcessingSerialSender() 
{
  Serial.print(paraChoquesEsq, DEC);
  Serial.print(",");
  Serial.print(paraChoquesDir, DEC);
  Serial.print(",");
  Serial.print(IVValor, DEC);
  Serial.print(",");
  Serial.print(navEstado, DEC);
  Serial.print(",");
  Serial.print(maxVelocidadeEsq, DEC);
  Serial.print(",");
  Serial.print(maxVelocidadeDir, DEC);
  Serial.print(",");
  Serial.print(numSaves, DEC);
  Serial.println();
  
}


unsigned long instanteAnterior;
unsigned long tempoProcesso = 4000;
boolean estadoProcesso = true;


int ProcessingUpdate() 
{
  unsigned long instanteActual = millis();
  
  if (instanteActual - instanteAnterior > tempoProcesso)
  {
    estadoProcesso = false;
    return estadoProcesso;
  }
  
  if (paraChoquesMetro.check()) { 
   paraChoquesEsq = farrusco.PChoqueEsqValor();
   paraChoquesDir = farrusco.PChoqueDirValor();
  }

  if (sensorIVMetro.check()) { 
    IVValor = farrusco.IVValor();
  }
  if(ProcessingSerialReciever()) {
    instanteAnterior = instanteActual;
    estadoProcesso = true;
  }
  
  return estadoProcesso;
  
}



