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

	//declara��o dos par� Choques frontais como entradas
	pinMode(pChoquesEsqPin, INPUT_PULLUP);
	pinMode(pChoquesDirPin, INPUT_PULLUP);
}

//Retorna o valor do par�-choques esquerdo. 1 - Pressionado, 0 - Caminho sem obst�culos
int ParaChoques::PChoqueEsqValor()
{
	return(digitalRead(pChoquesEsqPin));
}

//Retorna o valor do par�-choques direito. 1 - Pressionado, 0 - Caminho sem obst�culos
int ParaChoques::PChoqueDirValor()
{
	return(digitalRead(pChoquesDirPin));
}

