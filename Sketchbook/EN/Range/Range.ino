#include <Farrusco.h>

Farrusco farrusco;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);  
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{
  farrusco.neck.Range();
  Serial.println(farrusco.neck.GetPosition());
  delay(20);
}
