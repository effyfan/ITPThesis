String readString;

#include <AccelStepper.h>
AccelStepper stepper1(AccelStepper::DRIVER, 3, 2);
AccelStepper stepper2(AccelStepper::DRIVER, 6, 5);
AccelStepper stepper3(AccelStepper::DRIVER, 9, 8);
AccelStepper stepper4(AccelStepper::DRIVER, 12, 11);
AccelStepper stepper5(AccelStepper::DRIVER, 15, 14);
AccelStepper stepper6(AccelStepper::DRIVER, 18, 17);
AccelStepper stepper7(AccelStepper::DRIVER, 21, 20);
AccelStepper stepper8(AccelStepper::DRIVER, 24, 23);
AccelStepper stepper9(AccelStepper::DRIVER, 27, 26);
AccelStepper stepper10(AccelStepper::DRIVER, 30, 29);
int xp1;
int xp2;
int xp3;
int xp4;
int xp5;
int yp1;
int yp2;
int yp3;
int yp4;
int yp5;

// Define the Pins used
#define dir_pin1 2
#define step_pin1 3
#define home_switch1 4

#define dir_pin2 5
#define step_pin2 6
#define home_switch2 7

#define dir_pin3 8
#define step_pin3 9
#define home_switch3 10

#define dir_pin4 11
#define step_pin4 12
#define home_switch4 13

#define dir_pin5 14
#define step_pin5 15
#define home_switch5 16

#define dir_pin6 17
#define step_pin6 18
#define home_switch6 19

#define dir_pin7 20
#define step_pin7 21
#define home_switch7 22

#define dir_pin8 23
#define step_pin8 24
#define home_switch8 25

#define dir_pin9 26
#define step_pin9 27
#define home_switch9 28

#define dir_pin10 29
#define step_pin10 30
#define home_switch10 31

int direction;    // Variable to set Rotation (CW-CCW) of the motor
int steps1; // Used to set HOME position after Homing is completed
int steps2;
int steps3;
int steps4;
int steps5;
int steps6;
int steps7;
int steps8;
int steps9;
int steps10;

void setup() {
  Serial.begin(9600);
  pinMode(dir_pin1, OUTPUT);
  pinMode(step_pin1, OUTPUT);
  pinMode(home_switch1, INPUT_PULLUP);
  pinMode(dir_pin2, OUTPUT);
  pinMode(step_pin2, OUTPUT);
  pinMode(home_switch2, INPUT_PULLUP);
  pinMode(dir_pin3, OUTPUT);
  pinMode(step_pin3, OUTPUT);
  pinMode(home_switch3, INPUT_PULLUP);
  pinMode(dir_pin4, OUTPUT);
  pinMode(step_pin4, OUTPUT);
  pinMode(home_switch4, INPUT_PULLUP);
  pinMode(dir_pin5, OUTPUT);
  pinMode(step_pin5, OUTPUT);
  pinMode(home_switch5, INPUT_PULLUP);
  pinMode(dir_pin6, OUTPUT);
  pinMode(step_pin6, OUTPUT);
  pinMode(home_switch6, INPUT_PULLUP);
  pinMode(dir_pin7, OUTPUT);
  pinMode(step_pin7, OUTPUT);
  pinMode(home_switch7, INPUT_PULLUP);
  pinMode(dir_pin8, OUTPUT);
  pinMode(step_pin8, OUTPUT);
  pinMode(home_switch8, INPUT_PULLUP);
  pinMode(dir_pin9, OUTPUT);
  pinMode(step_pin9, OUTPUT);
  pinMode(home_switch9, INPUT_PULLUP);
  pinMode(dir_pin10, OUTPUT);
  pinMode(step_pin10, OUTPUT);
  pinMode(home_switch10, INPUT_PULLUP);

  // Start Homing Stepper Motor 1
  while (digitalRead(home_switch1)) {  // Do this until the switch is activated
    digitalWrite(dir_pin1, LOW);      // (HIGH = anti-clockwise / LOW = clockwise)
    digitalWrite(step_pin1, HIGH);
    delay(1);                       // Delay to slow down speed of Stepper
    digitalWrite(step_pin1, LOW);
    delay(1);
  }

  while (!digitalRead(home_switch1)) { // Do this until the switch is not activated
    digitalWrite(dir_pin1, HIGH);
    digitalWrite(step_pin1, HIGH);
    delay(10);                       // More delay to slow even more while moving away from switch
    digitalWrite(step_pin1, LOW);
    delay(10);
  }

  // Start Homing Stepper Motor 2
  while (digitalRead(home_switch2)) {
    digitalWrite(dir_pin2, LOW);
    digitalWrite(step_pin2, HIGH);
    delay(1);
    digitalWrite(step_pin2, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch2)) {
    digitalWrite(dir_pin2, HIGH);
    digitalWrite(step_pin2, HIGH);
    delay(10);
    digitalWrite(step_pin2, LOW);
    delay(10);
  }

  // Start Homing Stepper Motor 3
  while (digitalRead(home_switch3)) {
    digitalWrite(dir_pin3, LOW);
    digitalWrite(step_pin3, HIGH);
    delay(1);
    digitalWrite(step_pin3, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch3)) {
    digitalWrite(dir_pin3, HIGH);
    digitalWrite(step_pin3, HIGH);
    delay(10);
    digitalWrite(step_pin3, LOW);
    delay(10);
  }

  // Start Homing Stepper Motor 4
  while (digitalRead(home_switch4)) {
    digitalWrite(dir_pin4, LOW);
    digitalWrite(step_pin4, HIGH);
    delay(1);
    digitalWrite(step_pin4, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch4)) {
    digitalWrite(dir_pin4, HIGH);
    digitalWrite(step_pin4, HIGH);
    delay(10);
    digitalWrite(step_pin4, LOW);
    delay(10);
  }

  // Start Homing Stepper Motor 5
  while (digitalRead(home_switch5)) {
    digitalWrite(dir_pin5, LOW);
    digitalWrite(step_pin5, HIGH);
    delay(1);
    digitalWrite(step_pin5, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch5)) {
    digitalWrite(dir_pin5, HIGH);
    digitalWrite(step_pin5, HIGH);
    delay(10);
    digitalWrite(step_pin5, LOW);
    delay(10);
  }
  // Start Homing Stepper Motor 6
  while (digitalRead(home_switch6)) {
    digitalWrite(dir_pin6, LOW);
    digitalWrite(step_pin6, HIGH);
    delay(1);
    digitalWrite(step_pin6, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch6)) {
    digitalWrite(dir_pin6, HIGH);
    digitalWrite(step_pin6, HIGH);
    delay(10);
    digitalWrite(step_pin6, LOW);
    delay(10);
  }
  // Start Homing Stepper Motor 7
  while (digitalRead(home_switch7)) {
    digitalWrite(dir_pin7, LOW);
    digitalWrite(step_pin7, HIGH);
    delay(1);
    digitalWrite(step_pin7, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch7)) {
    digitalWrite(dir_pin7, HIGH);
    digitalWrite(step_pin7, HIGH);
    delay(10);
    digitalWrite(step_pin7, LOW);
    delay(10);
  }
  // Start Homing Stepper Motor 8
  while (digitalRead(home_switch8)) {
    digitalWrite(dir_pin8, LOW);
    digitalWrite(step_pin8, HIGH);
    delay(1);
    digitalWrite(step_pin8, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch8)) {
    digitalWrite(dir_pin8, HIGH);
    digitalWrite(step_pin8, HIGH);
    delay(10);
    digitalWrite(step_pin8, LOW);
    delay(10);
  }
  // Start Homing Stepper Motor 9
  while (digitalRead(home_switch9)) {
    digitalWrite(dir_pin9, LOW);
    digitalWrite(step_pin9, HIGH);
    delay(1);
    digitalWrite(step_pin9, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch9)) {
    digitalWrite(dir_pin9, HIGH);
    digitalWrite(step_pin9, HIGH);
    delay(10);
    digitalWrite(step_pin9, LOW);
    delay(10);
  }
  // Start Homing Stepper Motor 10
  while (digitalRead(home_switch10)) {
    digitalWrite(dir_pin10, LOW);
    digitalWrite(step_pin10, HIGH);
    delay(1);
    digitalWrite(step_pin10, LOW);
    delay(1);
  }
  while (!digitalRead(home_switch10)) {
    digitalWrite(dir_pin10, HIGH);
    digitalWrite(step_pin10, HIGH);
    delay(10);
    digitalWrite(step_pin10, LOW);
    delay(10);
  }

  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
  stepper5.setCurrentPosition(0);
  stepper6.setCurrentPosition(0);
  stepper7.setCurrentPosition(0);
  stepper8.setCurrentPosition(0);
  stepper9.setCurrentPosition(0);
  stepper10.setCurrentPosition(0);

  stepper1.setMaxSpeed(3000);
  stepper1.setAcceleration(500);
  stepper2.setMaxSpeed(3000);
  stepper2.setAcceleration(500);
  stepper3.setMaxSpeed(3000);
  stepper3.setAcceleration(500);
  stepper4.setMaxSpeed(3000);
  stepper4.setAcceleration(500);
  stepper5.setMaxSpeed(3000);
  stepper5.setAcceleration(500);
  stepper6.setMaxSpeed(3000);
  stepper6.setAcceleration(500);
  stepper7.setMaxSpeed(3000);
  stepper7.setAcceleration(500);
  stepper8.setMaxSpeed(3000);
  stepper8.setAcceleration(500);
  stepper9.setMaxSpeed(3000);
  stepper9.setAcceleration(500);
  stepper10.setMaxSpeed(3000);
  stepper10.setAcceleration(500);
}


void loop() {
  if (Serial.available()) {
//    int index1 = Serial.parseInt();
    int xPos1 = Serial.parseInt();
    int yPos1 = Serial.parseInt();
//    int index2 = Serial.parseInt();
    int xPos2 = Serial.parseInt();
    int yPos2 = Serial.parseInt();
//    int index3 = Serial.parseInt();
    int xPos3 = Serial.parseInt();
    int yPos3 = Serial.parseInt();
//    int index4 = Serial.parseInt();
    int xPos4 = Serial.parseInt();
    int yPos4 = Serial.parseInt();
//    int index5 = Serial.parseInt();
    int xPos5 = Serial.parseInt();
    int yPos5 = Serial.parseInt();

//    Serial.write(index1);
//    Serial.write(index2);
//    Serial.write(index3);
//    Serial.write(index4);
//    Serial.write(index5);
    Serial.write(xPos1);
    Serial.write(xPos2);
    Serial.write(xPos3);
    Serial.write(xPos4);
    Serial.write(xPos5);
    Serial.write(yPos1);
    Serial.write(yPos2);
    Serial.write(yPos3);
    Serial.write(yPos4);
    Serial.write(yPos5);

    //    if (xPos1 < 0 || xPos1 > 255) {
    //      int warning = 999;
    //      Serial.write(warning);
    //    } else {
    //    }

    if (stepper1.distanceToGo() == 0) {
      delay(50);
      xp1 = map(xPos1, 0, 255, 0, 16000);
      stepper1.moveTo(xp1);
      //            Serial.write(xPos1);
    }
    if (stepper2.distanceToGo() == 0) {
      delay(50);
      xp2 = map(xPos2, 0, 255, 0, 16000);
      stepper2.moveTo(xp2);
    }
    if (stepper3.distanceToGo() == 0) {
      delay(50);
      xp3 = map(xPos3, 0, 255, 0, 16000);
      stepper3.moveTo(xp3);
    }
    if (stepper4.distanceToGo() == 0) {
      delay(50);
      xp4 = map(xPos4, 0, 255, 0, 16000);
      stepper4.moveTo(xp4);
    }
    if (stepper5.distanceToGo() == 0) {
      delay(50);
      xp5 = map(xPos5, 0, 255, 0, 16000);
      stepper5.moveTo(xp5);
    }
    // move the Y motors
    if (stepper6.distanceToGo() == 0) {
      delay(50);
      yp1 = map(yPos1, 0, 255, 0, 16000);
      stepper6.moveTo(yp1);
    }
    if (stepper7.distanceToGo() == 0) {
      delay(50);
      yp2 = map(yPos2, 0, 255, 0, 16000);
      stepper7.moveTo(yp2);
    }
    if (stepper8.distanceToGo() == 0) {
      delay(50);
      yp3 = map(yPos3, 0, 255, 0, 16000);
      stepper8.moveTo(yp3);
    }
    if (stepper9.distanceToGo() == 0) {
      delay(50);
      yp4 = map(yPos4, 0, 255, 0, 16000);
      stepper9.moveTo(yp4);
    }
    if (stepper10.distanceToGo() == 0) {
      delay(50);
      yp5 = map(yPos5, 0, 255, 0, 16000);
      stepper10.moveTo(yp5);
    }
  }
  stepper1.run();
  stepper2.run();
  stepper3.run();
  stepper4.run();
  stepper5.run();
  stepper6.run();
  stepper7.run();
  stepper8.run();
  stepper9.run();
  stepper10.run();
}
