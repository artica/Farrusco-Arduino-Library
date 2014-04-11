#include <Farrusco.h>

/*

  Change state when a time interval is achieved
  
  see blink without delays example: http://arduino.cc/en/Tutorial/BlinkWithoutDelay

*/

Farrusco farrusco;
// --------------------------------------------------------------------------- TIME INTERVAL
// constants won't change. Used here to 
// set pin numbers:
const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 10000;           // interval at which to blink (milliseconds)


// --------------------------------------------------------------------------- NAVIGATION STATE

// 0 = obstacle avoidance
// 1 = follow light
int nav_state = 0;

// --------------------------------------------------------------------------- LDR
//Light Sensor
int LDRLeft_pin = 1;
int LDRRight_pin = 2;

int LDRLeft, LDRRight;

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
int maxSpeedLeft = 255;
int maxSpeedRight = 210;

int min_speed = 100;

int motorLeftSpeed, motorRightSpeed;

// --------------------------------------------------------------------------- IR SENSOR
//Distance sensor
int IRValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  // led 13
  pinMode (ledPin, OUTPUT);
  
  // led rgb
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
    
  delay(1000);
}

void loop() 
{
  Serial.println(nav_state);
  
  if (nav_state == 0) 
  {
    ObstacleAvoidance();
  }
  else 
  {
    FollowLight();
  }
  unsigned long currentMillis = millis();
  Serial.println(previousMillis);
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      nav_state = 0;
    } else {
      ledState = LOW;
      nav_state = 1;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  
}

