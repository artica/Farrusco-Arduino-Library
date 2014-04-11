#include <FarruscoPT.h>

FarruscoPT farrusco;
// --------------------------------------------------------------------------- LED RGB
//pins led
int vermelho_pin = 19;
int verde_pin = 18;
int azul_pin = 17;

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq;
int pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
//Variáveis de Calibração
int maxVelocidadeEsq = 235;
int maxVelocidadeDir = 255;

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
  
  // led rgb
  pinMode(vermelho_pin, OUTPUT);
  pinMode(verde_pin, OUTPUT);
  pinMode(azul_pin, OUTPUT);
    
  delay(1000);
}

void loop() 
{

  farrusco.Rotacao();
  
  IvValor = farrusco.IVValor();
  Serial.print(IvValor);
  Serial.print("  ");
  
  pChoquesEsq = farrusco.PChoqueEsqValor();  
  pChoquesDir = farrusco.PChoqueDirValor();

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
  if (servoPos < 90) {
    
    if (IvValor >= 300){  //estamos perto de um obstáculo
      digitalWrite(vermelho_pin, LOW);
      digitalWrite(verde_pin, HIGH);
      digitalWrite(azul_pin, LOW);
      
      velocidadeMotorDir = 0;
      velocidadeMotorEsq = maxVelocidadeEsq;

      // diminuir a velocidade do servo
      delay(250);
    }
    if(IvValor < 299) {
      digitalWrite(vermelho_pin, LOW);
      digitalWrite(verde_pin, LOW);
      digitalWrite(azul_pin, HIGH);
      
      velocidadeMotorDir = maxVelocidadeDir;
      velocidadeMotorEsq = maxVelocidadeEsq;
      // aumentar a velocidade do servo
      delay(50);
    }
  }
  
  // se 'servoPos' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (servoPos > 90) {
    
    if (IvValor >= 300) { //estamos perto de um obstáculo
      digitalWrite(vermelho_pin, LOW);
      digitalWrite(verde_pin, HIGH);
      digitalWrite(azul_pin, LOW);
      
      velocidadeMotorDir = maxVelocidadeDir;
      velocidadeMotorEsq = 0;

      // diminuir a velocidade do servo
      delay(250);
    }
    if(IvValor < 299) {
      digitalWrite(vermelho_pin, LOW);
      digitalWrite(verde_pin, LOW);
      digitalWrite(azul_pin, HIGH);
      
      velocidadeMotorDir = maxVelocidadeDir;
      velocidadeMotorEsq = maxVelocidadeEsq;
      
      // aumentar a velocidade do servo
      delay(50);
    }
  }
  delay(10);
  // chamada da função 'ActuadorMotores' atribuindo sempre os valores de rotação dos motores
  farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir); 
  }
}

