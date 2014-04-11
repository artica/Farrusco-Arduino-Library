#include <Farrusco.h>

Farrusco farrusco;
// --------------------------------------------------------------------------- LED RGB

int red_pin = 19;
int green_pin = 18;
int blue_pin = 17;

// --------------------------------------------------------------------------- SERVO
// value to be sent to the servo
int servoPos = 90;

// --------------------------------------------------------------------------- BUMPERS
int BLeft, BRight;

// --------------------------------------------------------------------------- MOTORES DC

// calibration variables, use it to perform a straight path
int maxSpeedLeft = 235;
int maxSpeedRight = 255;

int min_speed = 100;

int motorLeftSpeed, motorRightSpeed;

// --------------------------------------------------------------------------- IR SENSOR
int IRValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  // led rgb
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
    
  delay(1000);
}

void loop() 
{

  farrusco.Range();
  
  IRValue = farrusco.IRValueCheck();
  Serial.print(IRValue);
  Serial.print("  ");
  
  BLeft = farrusco.BLeftCheck();  
  BRight = farrusco.BRightCheck();

  servoPos = farrusco.GetPosition();
  Serial.println(servoPos);
  
  if (BLeft == 1) 
  {
    Beco (1);
  }
  else if (BRight == 1) 
  {
    Beco (2);
  }
  else 
  {
  // if 'servoPos' is less than 90, the robot is facing left
  // to move away, the right motor is stopped
  // this way, only the left motor is spinning
  if (servoPos < 90) {
    
    if (IRValue >= 300)   {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
      
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;

      // slow down servo speed
      delay(250);
    }
    if(IRValue < 299) {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      // speed up servo speed
      delay(50);
    }
  }
  
  // if 'servoPos' is over 90, the robot is facing right
  // to move away, the left motor is stopped
  // this way, only the right motor is spinning
  if (servoPos > 90) {
    if (IRValue >= 300) {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;

      // slow down servo speed
      delay(250);

    }
    if(IRValue < 299) {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      
      // speed up servo speed
     delay(50);

    }
  }
  delay(10);
  //call 'DiffTurn' with motors speed
  farrusco.DiffTurn(motorLeftSpeed, motorRightSpeed);
 
  }
}
