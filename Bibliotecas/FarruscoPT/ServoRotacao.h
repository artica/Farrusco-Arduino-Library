//Controlo da rotação do servo

#ifndef ServoRotacao_h
#define ServoRotacao_h
#include "Arduino.h"
#include "Servo.h"
 
class ServoRotacao{
	public:
		ServoRotacao();	
		ServoRotacao(int maximoServo, int minimoServo, int tempoDeEsperaServo, int incrServo, int servoPin, bool tipoServo);
		int Rotacao();
		void Roda();
		void Espera(int valor);
		int	ObterPosicao();
		void RotacaoValor(int servoMax, int servoMin, int servoInc);
		void RodaPosicao(int posServo);
		
	private:
		void Inicializacao(int maximoServo, int minimoServo, int tempoDeEsperaServo, int incrServo, int servoPin, bool tipoServo);
		int maxServo;
		int mimServo;
		int delServo;
		int incServo;
		Servo servo;
		bool tipoServo;
		int servoPos;
		int INC_POS;
		int DEC_POS;
		int dir;
		bool inicializado;	
		int tempoDeEspera;
		long tempoActual;
		int servoMax;
		int servoMin;
		int servoInc;
		int posServo;
};
#endif