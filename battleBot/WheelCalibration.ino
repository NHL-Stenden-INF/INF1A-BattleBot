// Pin Configuration
double leftOffsetPercentage = 1;      
double rightOffsetPercentage = 1;  

double pulsesLeft;
double pulsesRight;

// Adds pulses given for the given time to pulseAvg[Left, Right]
void addPulses(int time){
  int runtime = time + millis();
  int pulseLeftState;
  int pulseRightState;
  while(millis() < runtime){
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
  Serial.println(pulsesLeft);
  Serial.print(pulsesRight);
  Serial.println();
  double distanceRight = pulsesLeft;
  double distanceLeft = pulsesRight;
  double maxDistance = max(distanceLeft, distanceRight);
  leftOffsetPercentage = distanceLeft/maxDistance;
  rightOffsetPercentage = distanceRight/maxDistance;
  double e = rightOffsetPercentage*distanceLeft;
  double w = leftOffsetPercentage*distanceRight;
  Serial.println(distanceLeft);
  Serial.println(distanceRight);
  Serial.println(e);
  Serial.println(w);  
}

// Calculates wheel speed diffrence and match wheel speeds
void calibrate(){
    // Drive sequence to grab pulses per wheel
    driveLeft(255);
    Serial.print("Driving Left");
    Serial.println();
    addPulses(1000);
    addPulses(1000);
    addPulses(1000);
    addPulses(1000);
    driveStop();
    Serial.print("Stopped Driving");
    Serial.println();
    delay(1000);
    driveRight(255);
    Serial.print("Driving Right");
    Serial.println();
    addPulses(1000);
    addPulses(1000);
    addPulses(1000);
    addPulses(1000);
    driveStop();
    Serial.print("Stopped Driving");
    Serial.println();
}

void setCalibrationValues(){
    // Convert Pulse data to a 0-1 multiplier per wheel
    int maxPulses = max(pulsesLeft, pulsesRight);
    int minPulses = min(pulsesLeft, pulsesRight);
    double maxPulsesOffset = minPulses / maxPulses;
    Serial.print(maxPulsesOffset);
    Serial.println();
    Serial.println();
}

// Sets motor power to input
void setMotors(int LFWD, int LBACK, int RFWD, int RBACK){
  analogWrite(motorLeftFwd,   LFWD * rightOffsetPercentage);
  analogWrite(motorLeftBack,  LBACK * rightOffsetPercentage);
  analogWrite(motorRightFwd,  RFWD * leftOffsetPercentage);
  analogWrite(motorRightBack, RBACK * leftOffsetPercentage);
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
