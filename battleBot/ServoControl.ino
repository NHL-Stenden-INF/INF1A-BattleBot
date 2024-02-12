void servoControl() {
  // I need to fix this LOL
  digitalWrite(echoServo, LOW);
  delay(1500);
  // look forward
  for(int i = 0; i < 10; i++)
  {
    delay(20);
    digitalWrite(echoServo, HIGH);
    delayMicroseconds(1500);
    digitalWrite(echoServo, LOW);
  }
  digitalWrite(echoServo, LOW);
  delay(1500);
  
  // look left
  for(int i = 0; i < 10; i++)
  {
    delay(20);
    digitalWrite(echoServo, HIGH);
    delayMicroseconds(2500);
    digitalWrite(echoServo, LOW);
  }
  digitalWrite(echoServo, LOW);
  delay(1500);
  
  // look right
  for(int i = 0; i < 10; i++)
  {
    delay(20);
    digitalWrite(echoServo, HIGH);
    delayMicroseconds(500);
    digitalWrite(echoServo, LOW);
  }
}
