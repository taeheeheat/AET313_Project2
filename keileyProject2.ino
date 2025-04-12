#include <Servo.h>

const int NUM_HOUSES = 3;

//servo
Servo houseServos[NUM_HOUSES];
Servo wolfServo;

//servo pin
const int housePins[NUM_HOUSES] = {8, 9, 10}; //8-straw, 9-stick, 10-brick
const int wolfPin = 11;

//btn pin
const int pigBtns[NUM_HOUSES] = {2, 3, 4}; //2-straw, 3-stick, 4-brick
const int wolfBtns[NUM_HOUSES] = {5, 6, 7}; //5-straw, 6-stick, 7-brick
const int ledBtn = 12;
const int ledPin = 13;

// state check
bool houseOpen[NUM_HOUSES] = {false, false, false};
bool wolf = false;

void setup() {
  for (int i = 0; i < NUM_HOUSES; i++) {
    houseServos[i].attach(housePins[i]);
    pinMode(pigBtns[i], INPUT);
    pinMode(wolfBtns[i], INPUT);
  }
  wolfServo.attach(wolfPin);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Each pig makes each houses' servo turns 180 degree
  for (int i = 0; i < NUM_HOUSES; i++) {
    if (digitalRead(pigBtns[i]) == HIGH && !houseOpen[i]) {
      houseServos[i].write(180);
      houseOpen[i] = true;

      // brickPigBtn activates --> wolf servo give a wolf pieces
      if (i == 2) {
        if (!wolf) {
          wolfServo.write(90);
          wolf = true;
        } else {
          wolfServo.write(0);
          wolf = false;
        }
      }

      delay(100);
    }
  }

  // Wolf makes each houses' servo turns 0 degree
  for (int i = 0; i < NUM_HOUSES; i++) {
    if (digitalRead(wolfBtns[i]) == HIGH && houseOpen[i]) {
      houseServos[i].write(0);
      houseOpen[i] = false;

      delay(100);
    }
  }

  //when wolf is falling down to the pot
  if (digitalRead(ledBtn) == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
