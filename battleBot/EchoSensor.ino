void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(echoPinSend, LOW);
  delayMicroseconds(2);
  digitalWrite(echoPinSend, HIGH);
  delayMicroseconds(10);
  digitalWrite(echoPinSend, LOW);
  duration = pulseIn(echoPinRead, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  // Stop if distance is less than or equal to stopDistance
  if (distance <= stopDistance) {
    UpdateLights(255, 0, 0);
  } else {
    UpdateLights(0, 255, 0);
  }
}

void UpdateLights(int r, int g, int b){
    for(int i=0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(g, r, b));  
    }
     pixels.show();
}
