void ObstacleAvoidance() 
{

  farrusco.Rotacao();
  
  IvValor = farrusco.sensorDeDistancia.IVValor();
  delay(40);

  pChoquesEsq = farrusco.PChoqueEsqValor();  
  pChoquesDir = farrusco.PChoqueDirValor();
 
  servoPos = farrusco.ObterPosicao();
  
  if (pChoquesEsq == 1) 
  {
    digitalWrite(vermelho_pin, HIGH);
    digitalWrite(verde_pin, LOW);
    digitalWrite(azul_pin, LOW);
    Beco (1);
  }
  else if (pChoquesDir == 1) 
  {
    digitalWrite(vermelho_pin, HIGH);
    digitalWrite(verde_pin, LOW);
    digitalWrite(azul_pin, LOW);
    Beco (2);
  }
  else 
  {
    // se 'servoPos' for menor do que 90 quer dizer que estamos a olhar para a esquerda
    // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
    // girando apenas o motor da esquerda 
    if (servoPos < 90){
      
      if (IvValor >= 300){ //estamos perto de um obstáculo
        
        digitalWrite(vermelho_pin, LOW);
        digitalWrite(verde_pin, HIGH);
        digitalWrite(azul_pin, LOW);
        
        velocidadeMotorEsq = maxVelocidadeEsq;
        velocidadeMotorDir = 0;

        // diminui a velocidade so servo
       delay(250);
      }
      if(IvValor < 299){
        
        digitalWrite(vermelho_pin, LOW);
        digitalWrite(verde_pin, LOW);
        digitalWrite(azul_pin, HIGH);
        
        velocidadeMotorEsq = maxVelocidadeEsq;
        velocidadeMotorDir = maxVelocidadeDir;
        
        // aumenta a velocidade so servo
          delay(50);
      }
    }
    
    // se 'i' for maior do que 90 quer dizer que estamos a olhar para a direita
    // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
    // girando apenas o motor da direita 
    if (servoPos > 90){
      if (IvValor >= 300){ //estamos perto de um obstáculo
        
        digitalWrite(vermelho_pin, LOW);
        digitalWrite(verde_pin, HIGH);
        digitalWrite(azul_pin, LOW);
             
        velocidadeMotorEsq = 0;
        velocidadeMotorDir = maxVelocidadeDir;
  
        //diminui a velocidade do servo
        delay(250);
      }
      if(IvValor < 299){
        
        digitalWrite(vermelho_pin, LOW);
        digitalWrite(verde_pin, LOW);
        digitalWrite(azul_pin, HIGH);
        
        velocidadeMotorEsq = maxVelocidadeEsq;
        velocidadeMotorDir = maxVelocidadeDir;
        
        // aumenta a velocidade do servo
         delay(50);
      }
    }
    
    // chamada da função 'ActuadorMotores' atribuindo sempre os valores de rotação dos motores
    farrusco.ActuadorMotores(velocidadeMotorEsq,velocidadeMotorDir); 
  }

}
