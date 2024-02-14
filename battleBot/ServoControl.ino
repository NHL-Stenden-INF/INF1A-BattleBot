void echoSensorForward()
{
  moveGripper(1500, echoServo);
}

void echoSensorLeft()
{
  moveGripper(2500, echoServo);
}

void echoSensorRight()
{
  moveGripper(500, echoServo);
}

void gripperOpen()
{
  moveGripper(1600, gripperServo);
}

void gripperClose()
{
  moveGripper(1000, gripperServo);
}

void moveGripper(int pulseDuration, int servo)
{
  for(int i = 0; i < 10; i++)
  {
    delay(20);
    digitalWrite(servo, HIGH);
    delayMicroseconds(pulseDuration);
    digitalWrite(servo, LOW);
  }
}
