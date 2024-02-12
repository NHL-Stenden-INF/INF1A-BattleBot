const int motorLeftBack =   12;  // Motor A1 LB
const int motorLeftFwd =    11;  // Motor A2 LF
const int motorRightFwd =   10;  // Motor B1 RF
const int motorRightBack =  9;   // Motor B2 RB

const int motorLeftRead =   8;   // Arduino A0
const int motorRightRead =  7;   // Arduino A1

const int echoServo = 5;
const int gripperServo = 3;

void setup() {
  pinMode(motorLeftFwd,   OUTPUT);
  pinMode(motorLeftBack,  OUTPUT);
  pinMode(motorRightBack, OUTPUT);
  pinMode(motorRightFwd,  OUTPUT);
  pinMode(motorLeftRead,  INPUT);
  pinMode(motorRightRead, INPUT);
  pinMode(echoServo, OUTPUT);
  pinMode(gripperServo, OUTPUT);
  Serial.begin(9600);
  calibrate();
}

void loop() {
  driveForward(255);
}
