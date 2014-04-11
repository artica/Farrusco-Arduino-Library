//Servo Rotation Control
#ifndef ServoRange_h
#define ServoRange_h
#include "Arduino.h"
#include "Servo.h"
 
class ServoRange{

	public:
		ServoRange();	
		ServoRange(int maximumServo, int minimumServo, int delayServo, int incrServo, int servoPin, bool typeServo);
		int Range();
		void Rotate();
		int	GetPosition();
		void RangeValue(int servoMax, int servoMin, int incrementServo);
		void WritePos(int posServo);
		void Delay(int value);

	private:
		void Initializer(int maximumServo, int minimumServo, int delayServo, int incrServo, int servoPin, bool typeServo);
		int maxServo;
		int mimServo;
		int delServo;
		int incServo;
		Servo servo;
		bool typeServo;
		int servoPos;
		int INC_POS;
		int DEC_POS;
		int dir;
		bool initialized;
		int delay;
		long currentTime;
		int delayTime;
		int servoMax;
		int servoMin;
		int incrementServo;
		int posServo;

};

#endif