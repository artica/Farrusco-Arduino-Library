#include "FarruscoPT.h"
 
FarruscoPT::FarruscoPT()
{

}

FarruscoPT::FarruscoPT(int maximoServo, int minimoServo, int tempoDeEsperaServo, int incServo, int servoPin, bool tipoServo, int pChoquesEsqPin, int pChoquesDirPin, int ivPin, int motorA0, int motorA1, int motorB0, int motorB1)
{
	pescoco = ServoRotacao(maximoServo, minimoServo, tempoDeEsperaServo, incServo, servoPin, tipoServo);
	paraChoques = ParaChoques(pChoquesEsqPin, pChoquesDirPin);
	sensorDeDistancia = IV(ivPin);
	motores = Motor(motorA0, motorA1, motorB0, motorB1);
}

void FarruscoPT::ActuadorMotores(int velocidadeEsq, int velocidadeDir)
{
	motores.ActuadorMotores(velocidadeEsq, velocidadeDir);
}

int FarruscoPT::PChoqueEsqValor()
{
	paraChoques.PChoqueEsqValor();
}

int FarruscoPT::PChoqueDirValor()
{
	paraChoques.PChoqueDirValor();
}

int FarruscoPT::IVValor()
{
	sensorDeDistancia.IVValor();
}

int FarruscoPT::ObterPosicao()
{
	pescoco.ObterPosicao();
}

int FarruscoPT::Espera(int valor)
{
	pescoco.Espera(valor);
}

int FarruscoPT::Rotacao()
{
	pescoco.Rotacao();
}

void FarruscoPT::RotacaoValor(int servoMax, int servoMin, int incServo)
{
	pescoco.RotacaoValor(servoMax, servoMin, incServo);
}

void FarruscoPT::RodaPosicao(int posServo)
{
	pescoco.RodaPosicao(posServo);
}

void FarruscoPT::Recuar()
{
	motores.Recuar();
}

void FarruscoPT::Avancar()
{
	motores.Avancar();
}












   
