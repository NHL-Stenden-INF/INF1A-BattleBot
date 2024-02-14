bool detectWall(long distance)
{
  long duration;
  digitalWrite(echoPinSend, LOW);
  delayMicroseconds(2);
  digitalWrite(echoPinSend, HIGH);
  delayMicroseconds(10);
  digitalWrite(echoPinSend, LOW);
  duration = pulseIn(echoPinRead, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  // Stop if distance is less than or equal to stopDistance
  if (distance <= stopDistance) 
  {
    return true;
  } 
  else 
  {
    return false;
  }
}
