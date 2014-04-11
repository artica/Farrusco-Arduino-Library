#include "IR.h"

IR::IR()
{
	Initializer(0);
}
 
IR::IR(int IRPin)
{
	Initializer(IRPin);
}

//Returns the value read by the distance sensor
void IR::Initializer(int IRPin)
{	
	IRP = IRPin;
}

//Returns the value read by the distance sensor
int IR::IRValueCheck()
{
	return(analogRead(IRP));
}

//Returns the value read by the distance sensor in centimeters
float IR::IRValueMeters()
{
	float distancia = (4800/(analogRead(IRP)-20));
	
	return(distancia);
}
