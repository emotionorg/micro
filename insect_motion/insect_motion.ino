#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;

int minAngle = 0;
int maxAngle = 180;
int angle = minAngle;

void setup() {
    myservo.attach(7);  // attaches the servo on pin 7 to the servo object
    myservo2.attach(8);
}

void loop() {
  if (++angle == maxAngle) {
    angle = minAngle;
  }
  myservo.write(angle);
  myservo2.write(maxAngle - angle);
  delay(5);
}
