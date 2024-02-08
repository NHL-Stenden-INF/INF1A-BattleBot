const int motorLeftFwd = 11;            //Motor A2 LF
const int motorLeftBwd = 12;            //Motor A1 LB

const int motorRightFwd = 10;           //Motor B1 RF
const int motorRightBwd = 9;            //Motor B2 RB


const int motorLeftRead = 8;           //Arduino A0
const int motorRightRead = 7;          //Arduino A1

int nextUpdate;

void setup() {
    pinMode(motorLeftFwd, OUTPUT);
    pinMode(motorLeftBwd, OUTPUT);
    pinMode(motorRightFwd, OUTPUT);
    pinMode(motorRightBwd, OUTPUT);
    Serial.begin(9600);

    driveForward(255);
}

void loop() {
    if(millis() >= nextUpdate) {
        Serial.print(analogRead(motorLeftRead));
        Serial.println();
        nextUpdate = millis() + 100;
    }
    delay(100);
}

void setMotors(int LFWD, int LBACK, int RFWD, int RBACK) {
    analogWrite(motorLeftFwd, LFWD);
    analogWrite(motorLeftBwd, LBACK);
    analogWrite(motorRightFwd, RFWD);
    analogWrite(motorRightBwd, RBACK);
}

//Moves forward at 0-255 speed
void driveForward(int speed) {
    setMotors(speed, 0, speed, 0);
}

//
void driveBack(int speed) {
    setMotors(0, speed, 0, speed);
}