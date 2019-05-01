#include <AccelStepper.h>

// Define a stepper and the pins it will use
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

int pos = 3600;

void setup()
{  
  Serial.begin(9600);
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
}

void loop()
{
  if (stepper1.distanceToGo() == 0)
  {
    delay(500);
    pos = -pos;
    stepper1.moveTo(pos);
    stepper2.moveTo(pos);
    stepper3.moveTo(pos);
    stepper4.moveTo(pos);
    stepper5.moveTo(pos);
    stepper6.moveTo(pos);
    stepper7.moveTo(pos);
    Serial.println(pos);
  }
  stepper1.run();
  stepper2.run();
  stepper3.run();
  stepper4.run();
  stepper5.run();
  stepper6.run();

}
