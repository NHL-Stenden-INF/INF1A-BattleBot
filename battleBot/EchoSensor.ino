#include <Adafruit_NeoPixel.h>
#define PIN        2 
#define NUMPIXELS  4
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Pin Config
const int echoPinRead = A0; // Echo 
const int echoPinSend = A1; // Trigger 

// Variables
const int stopDistance = 10; // Distance threshold to stop the robot (in cm)

void setup() {
  pinMode(echoPinRead, INPUT);
  pinMode(echoPinSend, OUTPUT);
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
