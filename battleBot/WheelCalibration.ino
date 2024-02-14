double leftForwardOffset = 1;
double leftBackwardOffset = 1;    
double rightForwardOffset = 1;  
double rightBackwardOffset = 1;

// Drive sequence to calibrate the wheels
void calibrate()
{
    driveLeft(255);
    addPulses(4000, false, true);
    driveStop();
    delay(1000);
    driveRight(255);
    addPulses(4000, true, false);
    driveStop();
}

// Collects pulses for the given time and sets offset values 
void addPulses(int time, bool leftForward, bool rightForward)
{
  int runtime = time + millis();
  int pulseLeftState;
  int pulseRightState;
  double pulsesLeft;
  double pulsesRight;
  while(millis() < runtime)
  {
    // Detects pulse on left side
    if(pulseLeftState != digitalRead(motorLeftRead))
    {
      pulseLeftState = digitalRead(motorLeftRead);
      pulsesLeft++;
    }
    // Detects pulse on right side
    if(pulseRightState != digitalRead(motorRightRead))
    {
      pulseRightState = digitalRead(motorRightRead);
      pulsesRight++;
    }
    delay(10);
  }
  double maxPulses = max(pulsesLeft, pulsesRight);
  leftOffset  = pulsesLeft/maxPulses;
  RightOffset = pulsesRight/maxPulses;
  if(leftForward)
  {
    leftBackwardOffset  = leftOffset;
  }
  else
  {
    leftForwardOffset   = leftOffset;
  }
  if(rightForward)
  {
    rightBackwardOffset = rightOffset;
  }
  else
  {
    rightForwardOffset  = rightOffset;
  }
}
