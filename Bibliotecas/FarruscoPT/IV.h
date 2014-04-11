//Sensor Infravermelho - Permite saber a dist�ncia a um obst�culo

#ifndef IV_h
#define IV_h
#include "Arduino.h"
 
class IV{

	public:
		IV();	
		IV(int IVPin);
		int IVValor();
		float IVValorMetros();
		
	private:
		void Inicializacao(int IVPin);
		int IVP;

};

#endif