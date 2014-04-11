#include <FarruscoPT.h>
#include <IV.h>
#include <Motor.h>
#include <ParaChoques.h>
#include <ServoRotacao.h>
#include <Servo.h>



//Farrusco farrusco(140, 60, 25, 2, 8, 7, 0, 9, 6, 11, 3, 5);

FarruscoPT farrusco;
Servo servo;
int servoPin = 9;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);

  servo.attach(servoPin); // servo attach pin
  servo.write(90); // center servo
  
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{
  
//farrusco.pescoco.Range();
//delay(20);
int servoPos = farrusco.pescoco.Rotacao();
Serial.println(servoPos);
servo.write(servoPos);
delay(20);
}
