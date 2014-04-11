#include <FarruscoPT.h>

FarruscoPT farrusco;
// --------------------------------------------------------------------------- SERVO
int servoPos = 90;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq;
int pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
//Variáveis de calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 210;

int minVelocidade = 100;

int velocidadeMotorEsq;
int velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
//Sensor de distância
int IvValor;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
  
  farrusco.Rotacao();
  
  //imprime o valor do sensor de distância
  IvValor = farrusco.IVValor();
  Serial.print(IvValor);
  Serial.print("  ");

  pChoquesEsq = farrusco.PChoqueEsqValor();  
  pChoquesDir = farrusco.PChoqueDirValor();

  //imprime a posição do servo
  servoPos = farrusco.ObterPosicao();
  Serial.println(servoPos);
 
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
  if (servoPos > 90) {
    if (IvValor >= 300){ //estamos perto de um obstáculo
      velocidadeMotorDir = maxVelocidadeDir;
      velocidadeMotorEsq = 0;

      // diminuir a velocidade do servo
      delay(250);
    }
    if(IvValor < 299){
      velocidadeMotorDir= maxVelocidadeDir;
      velocidadeMotorEsq = maxVelocidadeEsq;
      
      // aumentar a velocidade do servo
      delay(50);
    }
  }
  
  // se 'servoPos' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (servoPos < 90) {
    if (IvValor >= 300){ //estamos perto de um obstáculo
      velocidadeMotorDir = 0;
      velocidadeMotorEsq = maxVelocidadeEsq;

      // slow down servo speed
     delay(250);
    }
    if(IvValor < 299){
      velocidadeMotorDir = maxVelocidadeDir;
      velocidadeMotorEsq = maxVelocidadeEsq;
      
      // speed up servo speed
      delay(50);
    }
  }
  
  // chamada da função 'ActuadorMotores' atribuindo sempre os valores de rotação dos motores
 farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  }  
}

