//Controlo do Motor

#ifndef Motor_h
#define Motor_h
#include "Arduino.h"
 
class Motor{

	public:
		Motor();	
		Motor(int dirMotorA0, int dirMotorA1, int esqMotorB0, int esqMotorB1);
		void Parar();
		void Avancar();
		void Recuar();
		void VirarDir();
		void VirarEsq();
		void ActuadorMotores(int velocidadeEsq, int velocidadeDir);
	
	private:
		void Inicializacao(int dirMotorA0, int dirMotorA1, int esqMotorB0, int esqMotorB1);
		int motor_A0;
		int motor_A1;
		int motor_B0;
		int motor_B1;

};
#endif