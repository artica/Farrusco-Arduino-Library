#include "Bumpers.h"
 
Bumpers::Bumpers()
{
	Initializer(8,7);	
}

Bumpers::Bumpers(int bumperLeft, int bumperRight)
{
	Initializer(bumperLeft, bumperRight);
}

void Bumpers::Initializer(int bumperLeft, int bumperRight)
{	
	bumperLeftPin = bumperLeft;
	bumperRightPin = bumperRight;
	
	// declare frontal Bumpers as inputs
	pinMode(bumperLeftPin, INPUT_PULLUP);
	pinMode(bumperRightPin, INPUT_PULLUP);
}

//Returns left bumper value. 1 - Contact detected, 0 - path clear
int Bumpers::BLeftCheck()
{
	return(digitalRead(bumperLeftPin));
}

//Returns right bumper value. 1 - Contact detected, 0 - path clear
int Bumpers::BRightCheck()
{
	return(digitalRead(bumperRightPin));
}

