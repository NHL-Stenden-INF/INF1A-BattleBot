void servoForward(){
  moveGripper(1500);
}

void servoLeft(){
  moveGripper(2500);
}

void servoRight(){
  moveGripper(500);
}

void moveGripper(int pulseDuration){
  for(int i = 0; i < 10; i++)
  {
    delay(20);
    digitalWrite(echoServo, HIGH);
    delayMicroseconds(pulseDuration);
    digitalWrite(echoServo, LOW);
  }
}
