#include "ServoRange.h"

ServoRange::ServoRange()
{
	Initializer(140, 60, 25, 2, 9, true);	
}

ServoRange::ServoRange(int maximumServo, int minimumServo, int delayServo, int incrServo, int servoPin, bool typeServo)
{
	Initializer(maximumServo, minimumServo, delayServo, incrServo, servoPin, typeServo);
}

void ServoRange::Initializer(int maximumServo, int minimumServo, int delayServo, int incrServo, int servoPin, bool typeServo)
{	
	maxServo = maximumServo;
	mimServo = minimumServo;
	delServo = delayServo;
	incServo = incrServo;

	typeServo = typeServo;
	servoPos = 90;
	INC_POS = 0;
	DEC_POS = 1;
	dir = 0;	//variable dir (direction) defines the servo rotation
	initialized = false;
	delayTime = 50;
	currentTime = 0;
	
}

//Places the servo in position servoPos
void ServoRange::Rotate()
{
	if(!initialized)
		servo.attach(9);
	initialized = true;
	if (typeServo)
		servo.write(servoPos);
	else
		servo.write(180-servoPos);
}

//Returns the currentes servo position
int ServoRange::GetPosition()
{
	return servoPos;
}

//Wait time
void ServoRange::Delay(int value)
{
	delay = value;
}

// Manages the servo rotation between the maximum and minimum value defaulted by the constructor
int ServoRange::Range()
{	
	if (currentTime + delayTime < millis())
	{
		if(servoPos >= maxServo) 
			dir = DEC_POS;

		if(servoPos <= mimServo) 
			dir = INC_POS;

		if(dir == INC_POS)
			servoPos += incServo;
		else	
			servoPos -= incServo;
	
		Rotate();		
		currentTime = millis();
	}
	return(servoPos);
}

//Manages the servo rotation between the maximum and minimum values received as arguments
void ServoRange::RangeValue(int servoMax, int servoMin, int incrementServo)
{
	if (currentTime + delayTime < millis())
	{
		if(servoPos >= servoMax) dir = DEC_POS;

		if(servoPos <= servoMin) dir = INC_POS;

		if(dir == INC_POS)
			servoPos += incrementServo;
		else	
			servoPos -= incrementServo;
		
		Rotate();
		currentTime = millis();
	}
}

//Move the servo to the position received as argument
void ServoRange::WritePos(int posServo)
{
	servoPos = posServo;
	Rotate();
	
}