#include "Farrusco.h"

Farrusco::Farrusco()
{

}

Farrusco::Farrusco(int maximumServo, int minimumServo, int delServo, int incServo, int servoPin, bool typeServo, int bumperLeftPin, int bumperRightPin, int irPin, int motorA0, int motorA1, int motorB0, int motorB1)
{
	neck = ServoRange(maximumServo, minimumServo, delServo, incServo, servoPin, typeServo);
	bumpers = Bumpers(bumperLeftPin, bumperRightPin);
	distanceSensor = IR(irPin);
	motors = DifferentialMotor(motorA0, motorA1, motorB0, motorB1);
}

int Farrusco::IRValueCheck()
{
	distanceSensor.IRValueCheck();
}

int Farrusco::BLeftCheck()
{
	bumpers.BLeftCheck();
}

int Farrusco::BRightCheck()
{
	bumpers.BRightCheck();
}

void Farrusco::DiffTurn(int speedLeft, int speedRight)
{
	motors.DiffTurn(speedLeft, speedRight);
}

int Farrusco::GetPosition()
{
	neck.GetPosition();
}

int Farrusco::Delay(int value)
{
	neck.Delay(value);
}

int Farrusco::Range()
{
	neck.Range();
}

void Farrusco::RangeValue(int servoMax, int servoMin, int incrementServo)
{
	neck.RangeValue(servoMax, servoMin, incrementServo);
}

void Farrusco::WritePos(int posServo)
{
	neck.WritePos(posServo);
}


















   
