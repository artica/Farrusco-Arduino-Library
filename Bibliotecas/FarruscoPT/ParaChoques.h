//ParaChoques - Permite ler o valor dos sensores de direc��o
#ifndef ParaChoques_h
#define ParaChoques_h
#include "Arduino.h"
 
class ParaChoques{

	public:
		ParaChoques();	
		ParaChoques(int paraChoquesEsq, int paraChoquesDir);
		int PChoqueEsqValor();
		int PChoqueDirValor();
		
	private:
		void Inicializacao(int paraChoquesEsq, int paraChoquesDir);
		int pChoquesEsqPin;
		int pChoquesDirPin;
};

#endif