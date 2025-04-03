#include <Servo.h> //changes test! 

Servo servo1; //create servo variable
const int buttonPin = 2; //sets pin to 2

void setup() {
  servo1.attach(9); // attaches the servo on pin 9
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH {
    servo1.write(90); //the servo turn to 90 degree
  } else {
    servo1.write(0);
  }
}
