#ifndef FarruscoPT_h
#define FarruscoPT_h
#include "Arduino.h"
#include "Motor.h"
#include "ServoRotacao.h"
#include "IV.h"
#include "ParaChoques.h"
 
class FarruscoPT{ 

	public:
		FarruscoPT();	
		FarruscoPT(int maximoServo, int minimoServo, int tempoDeEsperaServo, int incServo, int ServoPin, bool tipoServo, int pChoquesEsqPin, int pChoquesDirPin, int IVPin, int motorA0, int motorA1, int motorB0, int motorB1);
		ParaChoques paraChoques;
		Motor motores;
		IV sensorDeDistancia;
		ServoRotacao pescoco;
		void ActuadorMotores( int velocidadeEsq, int velocidadeDir);
		int PChoqueEsqValor();
		int PChoqueDirValor();
		int IVValor();
		int ObterPosicao();
		int Espera(int valor);
		int Rotacao();
		void RotacaoValor(int servoMax, int servoMin, int incServo);
		void RodaPosicao(int posServo);
		void Recuar();
		void Avancar();
		
		
	private:
		int velocidadeEsq;
		int velocidadeDir;
		int valor;
		int servoMax;
		int servoMin;
		int incServo;
		int PosServo;
};
#endif