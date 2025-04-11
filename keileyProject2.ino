#include <Servo.h>

const int NUM_HOUSES = 3;

// servo
Servo houseServos[NUM_HOUSES];
Servo wolfServo;

// servo pin
const int housePins[NUM_HOUSES] = {8, 9, 10}; //8-straw, 9-wood, 10-brick
const int wolfPin = 11;

// btn pin
const int pigBtns[NUM_HOUSES] = {2, 3, 4}; //2-straw, 3-wood, 4-brick
//마지막 led 버튼 추가하기
const int wolfBtns[NUM_HOUSES] = {5, 6, 7}; //5-straw, 6-wood, 7-brick

// LED pin
const int ledPin = 13;

// state check
bool houseOpen[NUM_HOUSES] = {false, false, false};
}

void setup() {
  for (int i = 0; i < NUM_HOUSES; i++) {
    houseServos[i].attach(housePins[i]);
    pinMode(pigBtns[i], INPUT);
    pinMode(wolfBtns[i], INPUT);
  }

  wolfServo.attach(wolfPin);
  pinMode(resetBtn, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Each pig makes each houses' servo turns 180 degree
  for (int i = 0; i < NUM_HOUSES; i++) {
    if (digitalRead(pigBtns[i]) == HIGH && !houseOpen[i]) {
      houseServos[i].write(180);
      houseOpen[i] = true;

      // if brickPigBtn activates --> wolf servo give a wolf pieces
      if (i == 2) {
        wolfServo.write(90);
      }

      delay(200);
    }
  }

  // Wolf makes each houses' servo turns 0 degree
  for (int i = 0; i < NUM_HOUSES; i++) {
    if (digitalRead(wolfBtns[i]) == HIGH && houseOpen[i]) {
      houseServos[i].write(0);
      houseOpen[i] = false;

      //cake led
      if (i == 2) {
        //코드 추가하기
      }

      delay(200);
    }
  }
}
