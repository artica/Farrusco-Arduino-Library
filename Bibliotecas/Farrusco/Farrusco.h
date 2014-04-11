#ifndef Farrusco_h
#define Farrusco_h
#include "Arduino.h"
#include "DifferentialMotor.h"
#include "ServoRange.h"
#include "IR.h"
#include "Bumpers.h"
 
class Farrusco{ 

	public:
		Farrusco();	
		Farrusco(int maximumServo, int minimumServo, int delServo, int incServo, int ServoPin, bool typeServo, int bumperLeftPin, int bumperRightPin, int IRPin, int motorA0, int motorA1, int motorB0, int motorB1);
		Bumpers bumpers;
		DifferentialMotor motors;
		IR distanceSensor;
		ServoRange neck;
		int IRValueCheck();
		int BLeftCheck();
		int BRightCheck();
		void DiffTurn(int speedLeft, int speedRight);
		int GetPosition();
		int Delay(int value);
		int Range();
		void RangeValue(int servoMax, int servoMin, int incrementServo);
		void WritePos(int posServo);
			
	private:
		int speedLeft; 
		int speedRight;
		int value;
		int servoMax;
		int servoMin;
		int incrementServo;
		int posServo;
};
#endif