// Define the Heart bitled's pin
const int pinPiscarLed = 13; 
int pinEstado = HIGH;

Metro heartBitLedMetro = Metro (250);

void HeartBitSetup() 
{
  pinMode(pinPiscarLed, OUTPUT);
}

void HeartBit () 
{
  
  if (heartBitLedMetro.check() == 1) { // verificar se o metro ultrapassou o seu intervalo
    if (pinEstado == HIGH) {
      pinEstado = LOW;
      heartBitLedMetro.interval(250); // Se o estado do LED é HIGH, o intervalo é definido com 0.25 segundos.
    }
    else {
      heartBitLedMetro.interval(250); //Se o estado do LED é LOW, o intervalo é definido com 1 segundo.
      pinEstado = HIGH;
    }
    digitalWrite(pinPiscarLed, pinEstado);
  }
}



