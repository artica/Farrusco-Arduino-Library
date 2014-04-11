#include "IV.h"

IV::IV()
{
	Inicializacao(0);
}
 
IV::IV(int IVPin)
{
	Inicializacao(IVPin);
}


void IV::Inicializacao(int IVPin)
{	
	IVP = IVPin;

}

//Retorna o valor lido pelo sensor de distância
int IV::IVValor()
{
	return(analogRead(IVP));
}

//Retorna o valor lido pelo sensor de distância em centimetros
float IV::IVValorMetros()
{
	float distancia = (4800/(analogRead(IVP)-20));
	
	return(distancia);
}


