#include "ParaChoques.h"
 
ParaChoques::ParaChoques()
{
	Inicializacao(8,7);	
}

ParaChoques::ParaChoques(int paraChoquesEsq, int paraChoquesDir)
{
	Inicializacao(paraChoquesEsq, paraChoquesDir);
}

void ParaChoques::Inicializacao(int paraChoquesEsq, int paraChoquesDir)
{	
	pChoquesEsqPin = paraChoquesEsq;
	pChoquesDirPin = paraChoquesDir;

	//declaração dos pará Choques frontais como entradas
	pinMode(pChoquesEsqPin, INPUT_PULLUP);
	pinMode(pChoquesDirPin, INPUT_PULLUP);
}

//Retorna o valor do pará-choques esquerdo. 1 - Pressionado, 0 - Caminho sem obstáculos
int ParaChoques::PChoqueEsqValor()
{
	return(digitalRead(pChoquesEsqPin));
}

//Retorna o valor do pará-choques direito. 1 - Pressionado, 0 - Caminho sem obstáculos
int ParaChoques::PChoqueDirValor()
{
	return(digitalRead(pChoquesDirPin));
}

