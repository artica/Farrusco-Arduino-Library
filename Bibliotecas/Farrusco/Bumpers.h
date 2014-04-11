//Bumpers - Allows to read the value of the distance sensors

#ifndef Bumpers_h
#define Bumpers_h
#include "Arduino.h"
 
class Bumpers{

	public:
		Bumpers();	
		Bumpers(int bumperLeft, int bumperRight);
		
		int BLeftCheck();
		int BRightCheck();
		
	private:
		void Initializer(int bumperLeft, int bumperRight);
		int bumperLeftPin;
		int bumperRightPin;
};

#endif