#include <Bumpers.h>
#include <DifferentialMotor.h>
#include <Farrusco.h>
#include <IR.h>
#include <ServoRange.h>




//Farrusco farrusco = Farrusco(140, 60, 25, 2, 8, 7, 0, 9, 6, 11, 3, 5);
//const int baudrate = 9600;
Farrusco farrusco;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  	int BLeft = farrusco.bumpers.BLeftCheck();	
	int BRight = farrusco.bumpers.BRightCheck();

        Serial.println(BLeft);
	Serial.print("  ");
	Serial.println(BRight);
        delay(10);
}
