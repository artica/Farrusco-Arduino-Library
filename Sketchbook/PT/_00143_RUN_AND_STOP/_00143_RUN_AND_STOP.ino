#include <FarruscoPT.h>


FarruscoPT farrusco;
// --------------------------------------------------------------------------- MOTORES DC
// calibration variables, use it to perform a straight path
int maxVelocidadeEsq = 235;
int maxVelocidaDir = 255;

int min_speed = 100;

int velocidadeMotorEsq, velocidadeMotorDir;

// --------------------------------------------------------------------------- IR SENSOR
int IVValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
  int IVValue = farrusco.IVValor();
  Serial.print(IVValue);
  Serial.print("   ");

  if (IVValue > 299)
  { 
   farrusco.Recuar();
   delay(500);
  }
  else
    farrusco.Avancar();   
}

