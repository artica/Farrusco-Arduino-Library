#include <FarruscoPT.h>
#include <IV.h>
#include <Motor.h>
#include <ParaChoques.h>
#include <ServoRotacao.h>
//#include <Servo.h>

Servo servo;

FarruscoPT farrusco;

void setup() 
{
  Serial.begin(9600);  
  servo.attach(9); // servo attach pin
  servo.write(90); // center servo  
  delay(1000); 
}

void loop() 
{
  int IRValue = farrusco.sensorDeDistancia.IVValor();
  delay(20);
  Serial.print(IRValue);
  Serial.print("  ");
  
  int IRmetros = farrusco.sensorDeDistancia.IVValorMetros();
  Serial.println(IRmetros);
}       

