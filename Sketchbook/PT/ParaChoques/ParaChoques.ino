#include <FarruscoPT.h>
#include <IV.h>
#include <Motor.h>
#include <ParaChoques.h>
#include <ServoRotacao.h>

//Farrusco farrusco = Farrusco(140, 60, 25, 2, 8, 7, 0, 9, 6, 11, 3, 5);
//const int baudrate = 9600;
FarruscoPT farrusco;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  	int BLeft = farrusco.paraChoques.PChoqueEsqValor();	
	int BRight = farrusco.paraChoques.PChoqueDirValor();

        Serial.println(BLeft);
	Serial.print("  ");
	Serial.println(BRight);
        delay(10);
}
