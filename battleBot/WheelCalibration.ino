
// Pin Configuration
float leftOffsetPercentage = 1;      
float rightOffsetPercentage = 1;  

int pulseAvgLeft;
int pulseAvgRight;

// Adds pulses given for the given time to pulseAvg[Left, Right]
void addPulses(int time){
  int runtime = time + millis();
  int pulseLeftState;
  int pulseRightState;
  while(millis() < runtime){
    // Detects pulse on left side
    if(pulseLeftState != digitalRead(motorLeftRead)){
      pulseLeftState = digitalRead(motorLeftRead);
      pulseAvgLeft++;
    }
    // Detects pulse on right side
    if(pulseRightState != digitalRead(motorRightRead)){
      pulseRightState = digitalRead(motorRightRead);
      pulseAvgRight++;
    }
    delay(10);
  }
}

// Calculates wheel speed diffrence and match wheel speeds
void calibrate(){
    // Drive sequence to grab pulses per wheel
    driveLeft(255);
    Serial.print("Driving Left");
    Serial.println();
    addPulses(4000);
    driveStop();
    Serial.print("Stopped Driving");
    Serial.println();
    delay(1000);
    driveRight(255);
    Serial.print("Driving Right");
    Serial.println();
    addPulses(4000);
    driveStop();
    Serial.print("Stopped Driving");
    Serial.println();
    pulseAvgLeft /= 2;
    pulseAvgRight /= 2;
    // Convert Pulse data to a 0-1 multiplier per wheel
    int maxPulses = max(pulseAvgLeft, pulseAvgRight);
    leftOffsetPercentage = map(pulseAvgLeft, 0, maxPulses, 0, 100);
    rightOffsetPercentage = map(pulseAvgRight, 0, maxPulses, 0, 100);
    leftOffsetPercentage /= 100;
    rightOffsetPercentage /= 100;
    Serial.print(leftOffsetPercentage);
    Serial.println();
    Serial.print(rightOffsetPercentage);
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
