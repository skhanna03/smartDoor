#include <Servo.h>

Servo lockServo;
const int SENSOR = 7;
const int SERVO = 9;

// This runs first, inits everything
void setup() {
  Serial.begin(9600); // sample at 9600 baud frequency
  pinMode(SENSOR, INPUT); // getting data from sensor input
  lockServo.attach(9); // set up servo
}

void openLock() {
    lockServo.write(180);
}

void closeLock() {
    lockServo.write(0);
}

void loop() {
    const int pause = 5000;
    while (true) {
        // read the state of the the input pin:
        while (digitalRead(SENSOR) == LOW) {}; // stuck in loop until sense press
        
        openLock();
        delay(pause); // time for door to open
        closeLock();
    }
}
  
