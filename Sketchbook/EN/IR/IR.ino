#include <Bumpers.h>
#include <DifferentialMotor.h>
#include <Farrusco.h>
#include <IR.h>
#include <ServoRange.h>

//Farrusco farrusco = Farrusco(140, 60, 25, 2, 8, 7, 0, 9, 6, 11, 3, 5);
Farrusco farrusco;

void setup() 
{
  Serial.begin(9600);
  delay(1000);
}

void loop() 
{
	int IRValue = farrusco.distanceSensor.IRValueCheck();
	delay(20);
  
        Serial.println(IRValue);
}
