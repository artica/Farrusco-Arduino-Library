
// --------------------------------------------------------------------------- UPDATE

void obstacleAvoidanceUpdate() 
{
   pChoquesEsq = farrusco.PChoqueEsqValor();
   pChoquesDir = farrusco.PChoqueDirValor();
  
  if (sensorIVMetro.check() == 1) { 
   IvValor = farrusco.IVValor();
   sensorIVMetro.reset();
  }
    farrusco.RotacaoValor(servoMax, servoMin, servoInc);
    farrusco.Espera(servoDel);
    
    servoPos = farrusco.ObterPosicao();
  
  // 1 = pará choques esquerdo // 2 = pará choques direito // 0 = Nenhum pará choques pressionado
  if (!checkDeadEnd())  // igual a (checkDeadEnd() == 0)
  {  

    velocidadeMotorDir = maxVelocidadeDir;
    velocidadeMotorEsq = maxVelocidadeEsq;
    
    //aumenta a velocidade do servo e altera o valor máx, min, delay de rotação
    servoDel = 45;
    servoMin = 20;
    servoMax = 160;
    
    if (IvValor >= 300)    //estamos perto de um obstáculo
    {   
      if (servoPos < 90) 
      {
        Serial.println("if (servoPos < 90)");
        velocidadeMotorDir = 0;
        
        //diminui a velocidade do servo e altera o valor máx, min, delay de rotação
        servoDel = 250;
        servoMin = 20;
        servoMax = 80;
      }
      else //if (servoPos > 90) 
      {
        Serial.println("if (servoPos > 90)");
        velocidadeMotorEsq = 0;  
        
        // diminui a velocidade do servo e altera o valor máx, min, delay de rotação
        servoDel = 250;
        servoMin = 110;
        servoMax = 160;
      }
    }
    // chamada da função 'ActuadorMotores' atribuindo sempre os valores de rotação dos motores
   farrusco.ActuadorMotores(velocidadeMotorEsq,velocidadeMotorDir);
  }
}


