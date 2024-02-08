
// Pin Configuration
const int motorLeftBack =   12;  // Motor A1 LB
const int motorLeftFwd =    11;  // Motor A2 LF
const int motorRightFwd =   10;  // Motor B1 RF
const int motorRightBack =  9;   // Motor B2 RB

const int motorLeftRead =   8;   // Arduino A0
const int motorRightRead =  7;   // Arduino A1

void setup() {
  pinMode(motorLeftFwd,   OUTPUT);
  pinMode(motorLeftBack,  OUTPUT);
  pinMode(motorRightBack, OUTPUT);
  pinMode(motorRightFwd,  OUTPUT);
  pinMode(motorLeftRead,  INPUT);
  pinMode(motorRightRead, INPUT);
  Serial.begin(19200);
  calibrate();
}

void loop() {
  
}

// Calculates wheel speed diffrence and match wheel speeds
void calibrate(){
    driveLeft(255);
    delay(500);
    getPulses(1000);
    driveStop();
    delay(500);
    driveLeft(255);
    delay(500)
    getPulses(1000);
    driveStop();
}

// Outputs the pulses given for time
void getPulses(int time){
  int runtime = time + millis();
  int pulsesRight;
  int pulsesLeft;
  int pulseLeftState;
  int pulseRightState;
  while(millis() >= runtime){
    // Detects pulse on left side
    if(pulseLeftState != digitalRead(motorLeftRead)){
      pulseLeftState = digitalRead(motorLeftRead);
      pulsesLeft++;
    }
    // Detects pulse on right side
    if(pulseRightState != digitalRead(motorRightRead)){
      pulseRightState = digitalRead(motorRightRead);
      pulsesRight++;
    }
    delay(10);
  }
//  Serial.print("Left Pulses in a second");
//  Serial.print(pulsesLeft);
//  Serial.println();
//  Serial.print("Right Pulses in a second");
//  Serial.print(pulsesRight);
//  Serial.println();
}

// Sets motor power to input
void setMotors(int LFWD, int LBACK, int RFWD, int RBACK){
  analogWrite(motorLeftFwd,   LFWD);
  analogWrite(motorLeftBack,  LBACK);
  analogWrite(motorRightFwd,  RFWD);
  analogWrite(motorRightBack, RBACK);
}

// Rotate left at 0-255 speed
void driveLeft(int speed){
  setMotors(0, speed, speed, 0);
}

// Rotate right at 0-255 speed
void driveRight(int speed){
  setMotors(speed, 0 , 0, speed);
}

// Drive forwards at 0-255 speed
void driveForward(int speed){
  setMotors(speed, 0 , speed, 0);
}

// Drive backwards at 0-255 speed
void driveBack(int speed){
  setMotors(0, speed, 0, speed);
}

// Stop driving
void driveStop(){
  setMotors(0, 0, 0, 0);
}
}
