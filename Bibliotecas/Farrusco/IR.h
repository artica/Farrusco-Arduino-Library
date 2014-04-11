//Infrared Sensor - allows to know the distance to an obstacle

#ifndef IR_h
#define IR_h
#include "Arduino.h"
 
class IR{

	public:
		IR();	
		IR(int IRPin);
		int IRValueCheck();
		float IRValueMeters();
		
	private:
		void Initializer(int IRPin);
		int IRP;
};

#endif