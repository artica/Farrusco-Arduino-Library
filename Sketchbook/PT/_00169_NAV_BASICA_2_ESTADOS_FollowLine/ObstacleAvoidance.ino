void ObstacleAvoidance() 
{

  farrusco.Rotacao();
  
  IvValor = farrusco.IVValor();

  pChoquesEsq = farrusco.PChoqueEsqValor();  
  pChoquesDir = farrusco.PChoqueDirValor();
 
  if (pChoquesEsq == 1) 
  {
    Beco (1);
  }
  else if (pChoquesDir == 1) 
  {
    Beco (2);
  }
  else 
  {
  // se 'servoPos' for menor do que 90 quer dizer que estamos a olhar para a esquerda
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
  // girando apenas o motor da esquerda 
  if (servoPos < 90) {
    
    if (IvValor >= 300)   { //estamos perto de um obstáculo
      velocidadeMotorEsq = maxVelocidadeEsq;
      velocidadeMotorDir = 0;

      // slow down servo speed
      delay(250);
    }
    if(IvValor < 299) {
      
      velocidadeMotorEsq = maxVelocidadeEsq;
      velocidadeMotorDir = maxVelocidadeDir;
      
      // aumentar a velocidade do servo
      delay(50);
    }
  }
  
  // se 'servoPos' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (servoPos > 90) {
    
    if (IvValor >= 300) { //estamos perto de um obstáculo
      velocidadeMotorEsq = 0;

      // diminuir a velocidade do servo
      delay(250);
    }
    if(IvValor < 299) {
      
      velocidadeMotorDir = maxVelocidadeDir;
      velocidadeMotorEsq = maxVelocidadeEsq;
      
      // aumentar a velocidade do servo
       delay(50);
    }
  }
  
  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  farrusco.ActuadorMotores(velocidadeMotorEsq,velocidadeMotorDir); 
  }
}
