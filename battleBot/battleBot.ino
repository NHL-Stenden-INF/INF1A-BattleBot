// Neopixel Setup
#include <Adafruit_NeoPixel.h>
#define PIN        2 
#define NUMPIXELS  4
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Motor Pins
const int motorLeftBack =   12;  // Motor A1 LB
const int motorLeftFwd =    11;  // Motor A2 LF
const int motorRightFwd =   10;  // Motor B1 RF
const int motorRightBack =  6;   // Motor B2 RB

const int motorLeftRead =   8;   // Arduino A0
const int motorRightRead =  7;   // Arduino A1

// Echo Sensor Pins
const int echoServo = 5;
const int echoPinRead = A0; // Echo 
const int echoPinSend = A1; // Trigger 
const int stopDistance = 10; // Distance threshold to stop the robot (in cm)

// Gripper Pins
const in gripperServo = 3;

void setup() {
  // Motor
  pinMode(motorLeftFwd,   OUTPUT);
  pinMode(motorLeftBack,  OUTPUT);
  pinMode(motorRightBack, OUTPUT);
  pinMode(motorRightFwd,  OUTPUT);
  pinMode(motorLeftRead,  INPUT);
  pinMode(motorRightRead, INPUT);
  // Echo Sensor
  pinMode(echoPinRead, INPUT);
  pinMode(echoPinSend, OUTPUT);
  // 
  Serial.begin(9600);
  calibrate();
  driveForward(255);
  addPulses(10000);
}

void loop() {
  
}
