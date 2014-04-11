#include"Motor.h"

Motor::Motor() 
{
	Inicializacao(3,5,6,11);
}

Motor::Motor(int dirMotorA0, int dirMotorA1, int esqMotorB0, int esqMotorB1)
{
	Inicializacao(dirMotorA0, dirMotorA1, esqMotorB0, esqMotorB1);
}

void Motor::Inicializacao(int dirMotorA0, int dirMotorA1, int esqMotorB0, int esqMotorB1)
{
	motor_A0 = dirMotorA0;
	motor_A1 = dirMotorA1;
	motor_B0 = esqMotorB0;
	motor_B1 = esqMotorB1;
	
	//os pins de controlo do motor são saídas
	pinMode(motor_A0, OUTPUT);
	pinMode(motor_A1, OUTPUT);
	pinMode(motor_B0, OUTPUT);
	pinMode(motor_B1, OUTPUT);
}

// Farrusco pará
void Motor::Parar()
{
	ActuadorMotores(0, 0);
}

//Farrusco anda para a frente
void Motor::Avancar()
{
	ActuadorMotores(255, 255);
}

//Farrusco anda para trás
void Motor::Recuar()
{
	ActuadorMotores(-255,-255);
}

//Farrusco vira para a direita
void Motor::VirarDir()
{
	ActuadorMotores(255 ,-255);
}	

//Farrusco vira para a esquerda		
void Motor::VirarEsq()
{
	ActuadorMotores(-255, 255);
}

// Recebe como parametros as velocidades de cada motor
void Motor::ActuadorMotores(int velocidadeEsq, int velocidadeDir)
{
	if (velocidadeEsq > 0) 
	{  
		analogWrite(motor_B0, velocidadeEsq);
		digitalWrite(motor_B1, LOW);
	} 
 
	if (velocidadeEsq < 0) 
	{  
		digitalWrite(motor_B0, LOW);
		analogWrite(motor_B1, velocidadeEsq*-1); 
	}
 
	if (velocidadeEsq == 0) 
	{  
		digitalWrite(motor_B0, LOW);
		digitalWrite(motor_B1, LOW); 
	}
  
	if (velocidadeDir > 0) 
	{
		analogWrite(motor_A0, velocidadeDir);
		digitalWrite(motor_A1, LOW);
	}
 
	if (velocidadeDir < 0) 
	{
		digitalWrite(motor_A0, LOW);
		analogWrite(motor_A1, velocidadeDir*-1); 
	}
 
	if (velocidadeDir == 0)
	{
		digitalWrite(motor_A0, LOW);
		digitalWrite(motor_A1, LOW);
	}
}