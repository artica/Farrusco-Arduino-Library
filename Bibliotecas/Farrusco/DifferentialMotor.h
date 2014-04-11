//Motor Control

#ifndef DifferentialMotor_h
#define DifferentialMotor_h
#include "Arduino.h"
 
class DifferentialMotor{

	public:
		DifferentialMotor();	
		DifferentialMotor(int rightMotorA0, int rightMotorA1, int leftMotorB0, int leftMotorB1);
		void StopMotor();
		void ForwardMotor();
		void BackwardMotor();
		void TurnRightMotor();
		void TurnLeftMotor();
		void DiffTurn(int speedLeft, int speedRight);
	
	private:
		void Initializer(int rightMotorA0, int rightMotorA1, int leftMotorB0, int leftMotorB1);
		int motor_A0;
		int motor_A1;
		int motor_B0;
		int motor_B1;

};
#endif