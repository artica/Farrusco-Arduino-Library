#include"DifferentialMotor.h"

DifferentialMotor::DifferentialMotor() 
{
	Initializer(3,5,6,11);
}

DifferentialMotor::DifferentialMotor(int rightMotorA0, int rightMotorA1, int leftMotorB0, int leftMotorB1)
{
	Initializer(rightMotorA0, rightMotorA1, leftMotorB0, leftMotorB1);
}

void DifferentialMotor::Initializer(int rightMotorA0, int rightMotorA1, int leftMotorB0, int leftMotorB1)
{
	motor_A0 = rightMotorA0;
	motor_A1 = rightMotorA1;
	motor_B0 = leftMotorB0;
	motor_B1 = leftMotorB1;
	
  //the motor control wires are outputs
	pinMode(motor_A0, OUTPUT);
	pinMode(motor_A1, OUTPUT);
	pinMode(motor_B0, OUTPUT);
	pinMode(motor_B1, OUTPUT);
}
//Farrusco Stop
void DifferentialMotor::StopMotor()
{
	DiffTurn(0, 0);
}

//Farrusco go forward
void DifferentialMotor::ForwardMotor()
{
	DiffTurn(255, 255);
}

//Farrusco go backward
void DifferentialMotor::BackwardMotor()
{
	DiffTurn(-255, -255); 
}

//Farrusco turn right
void DifferentialMotor::TurnRightMotor()
{
	DiffTurn(255, -255);
}	

//Farrusco turn left		
void DifferentialMotor::TurnLeftMotor()
{
	DiffTurn(-255, 255);
}

//Recieve each motor velocity as argument
void DifferentialMotor::DiffTurn(int speedLeft, int speedRight)
{
	if (speedLeft > 0) 
	{  
		analogWrite(motor_B0, speedLeft);
		digitalWrite(motor_B1, LOW);
	} 
 
	if (speedLeft < 0) 
	{  
		digitalWrite(motor_B0, LOW);
		analogWrite(motor_B1, speedLeft*-1); 
	}
 
	if (speedLeft == 0) 
	{  
		digitalWrite(motor_B0, LOW);
		digitalWrite(motor_B1, LOW); 
	}
  
	if (speedRight > 0) 
	{
		analogWrite(motor_A0, speedRight);
		digitalWrite(motor_A1, LOW);
	}
 
	if (speedRight < 0) 
	{
		digitalWrite(motor_A0, LOW);
		analogWrite(motor_A1, speedRight*-1); 
	}
 
	if (speedRight == 0)
	{
		digitalWrite(motor_A0, LOW);
		digitalWrite(motor_A1, LOW);
	}
}