#include "ServoRotacao.h"

ServoRotacao::ServoRotacao()
{
	Inicializacao(140, 60, 25, 2, 9, true);
}

ServoRotacao::ServoRotacao(int maximoServo, int minimoServo, int tempoDeEsperaServo, int incrServo, int servoPin, bool tipoServo)
{
	Inicializacao(maximoServo, minimoServo, tempoDeEsperaServo, incrServo, servoPin, tipoServo);
}

void ServoRotacao::Inicializacao(int maximoServo, int minimoServo, int tempoDeEsperaServo, int incrServo, int servoPin, bool tipoServo)
{	
	maxServo = maximoServo;
	mimServo = minimoServo;
	delServo = tempoDeEsperaServo;
	incServo = incrServo;

	tipoServo = tipoServo;
	servoPos = 90;
	INC_POS = 0;
	DEC_POS = 1;
	dir = 0;
	inicializado = false;
	tempoDeEspera = 50;
	tempoActual = 0;
}

// Coloca o servo na posição servoPos
void ServoRotacao::Roda()
{
	if(!inicializado)
		servo.attach(9);
	inicializado = true;
	if (tipoServo)
		servo.write(servoPos);
	else
		servo.write(180-servoPos);
}

//Retorna a posição em que o servo se encontra
int ServoRotacao::ObterPosicao()
{
	return servoPos;
}

//Tempo de espera
void ServoRotacao::Espera(int valor)
{
	tempoDeEspera = valor;
}

// Gere a rotação do servo entre o valor máximo e mínimo definidos por defeito no construtor
int ServoRotacao::Rotacao()
{
	if (tempoActual + tempoDeEspera < millis())
	{
		if(servoPos >= maxServo) dir = DEC_POS;

		if(servoPos <= mimServo) dir = INC_POS;

		if(dir == INC_POS)
			servoPos += incServo;
		else	
			servoPos -= incServo;
		
		Roda();
		tempoActual = millis();
	}
	return(servoPos);
}

//Gere a rotação do servo entre o valor máximo e mínimo recebendo estes por parâmetros 
void ServoRotacao::RotacaoValor(int servoMax, int servoMin, int incServo)
{
	if (tempoActual + tempoDeEspera < millis())
	{
		if(servoPos >= servoMax) dir = DEC_POS;

		if(servoPos <= servoMin) dir = INC_POS;

		if(dir == INC_POS)
			servoPos += incServo;
		else	
			servoPos -= incServo;
		
		Roda();
		tempoActual = millis();
	}
}

//Desloca o servo para a posição recebida por argumento
void ServoRotacao::RodaPosicao(int posServo)
{
	servoPos = posServo;
	Roda();
}