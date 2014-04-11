#include <FarruscoPT.h>

FarruscoPT farrusco;

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{

  farrusco.motores.Parar();
  delay(1000);
  farrusco.motores.Avancar();
  delay(1000);
  farrusco.motores.VirarDir();
  delay(1000);
  farrusco.motores.VirarEsq();
  delay(1000);
  farrusco.motores.Recuar();
  delay(5000);
  farrusco.motores.Parar();
  delay(1000);

}

/*  
  // acelera
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    Serial.println("Estounoacelarar");
      farrusco.motores.DiffTurn(-fadeValue, -fadeValue);  
      delay(50);
  }
  
  // desacelera
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    Serial.println("Estounodesacelarar");
    farrusco.motores.DiffTurn(fadeValue, -fadeValue);
    delay(50);
  }

/*
  farrusco.motores.DiffTurn(255, 255);  
  Serial.println("255, 255 - frente");
  delay(1500);  
 
  farrusco.motores.DiffTurn(-255, -255);  
  Serial.println("-255, -255 - tras");
  delay(1500);  
  
  farrusco.motores.DiffTurn(0, 0);  
  Serial.println("0, 0 - stop");
  delay(1500);  
  
  farrusco.motores.DiffTurn(-255, 255);  
  Serial.println("-255, 255 - left");  
  delay(1500);  
  
  farrusco.motores.DiffTurn(255, -255);
  Serial.println("255, -255 - right");
  delay(1500);
} */

