#include <FarruscoPT.h>

/*

  Change state when a time intervalo is achieved
  
  see blink without delays example: http://arduino.cc/en/Tutorial/BlinkWithoutDelay

*/

FarruscoPT farrusco;
// --------------------------------------------------------------------------- TIME intervalo
const int ledPin =  13;      // número do pin do LED

int ledEstado = LOW;             // ledEstado é usada para alterar o estado do LED
long instanteAnterior = 0;        // guarda o último instante em que o LED teve aceso

// a variável é um long pois o tempo é medido em milisegundos, logo o número
// irá ultrapassar rapidamente o valor máximo que pode ser dado a um int
long intervalo = 10000;           // intervalo de tempo para piscar (milisegundos)


// --------------------------------------------------------------------------- NAVEGAÇÃO ESTADO
// 0 = obstacle avoidance
// 1 = follow light
int navEstado = 0;

// --------------------------------------------------------------------------- LDR
//Sensor de luminosidade
int LDREsq_pin = 1;
int LDRDir_pin = 2;

int LDREsq, LDRDir;

// --------------------------------------------------------------------------- LED RGB
// pins dos LEDS
int vermelho_pin = 19;
int verde_pin = 18;
int azul_pin = 17;

// --------------------------------------------------------------------------- SERVO
// o valor para ser enviado ao servo
int servoPos = 90;

// --------------------------------------------------------------------------- PARÁ CHOQUES
int pChoquesEsq, pChoquesDir;

// --------------------------------------------------------------------------- MOTORES DC
// Variáveis de calibração
int maxVelocidadeEsq = 255;
int maxVelocidadeDir = 210;

int minVelocidade = 100;

int velocidadeMotorEsq, velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
//Sensor de distância
int IvValor;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  // led 13
  pinMode (ledPin, OUTPUT);
  
  // led rgb
  pinMode(vermelho_pin, OUTPUT);
  pinMode(verde_pin, OUTPUT);
  pinMode(azul_pin, OUTPUT);
    
  delay(1000);
}

void loop() 
{
  //imprime o estado de navegação activo
  Serial.print("navEstado:");
  Serial.println(navEstado);
  
  if (navEstado == 0) 
  {
    ObstacleAvoidance();
  }
  else 
  {
    FollowLight();
  }
  unsigned long instanteActual = millis();
 
  if(instanteActual - instanteAnterior > intervalo) {
    //guarda o último instante em que o LED esteve aceso
    instanteAnterior = instanteActual;   

    // Se o LED esta ligado desliga e vice-versa
    if (ledEstado == LOW) {
      ledEstado = HIGH;
      navEstado = 0;
    } else {
      ledEstado = LOW;
      navEstado = 1;
    }
    //actualiza o LED com a variável ledEstado
    digitalWrite(ledPin, ledEstado);
  }
  
}

