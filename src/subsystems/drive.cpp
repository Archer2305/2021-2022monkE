#include "main.h"

using namespace okapi;

/*
right front: port 6
right top: port 1
right bottom: port 10

left front: port:4
left top: port 14
left bottom: port 1
*/
Motor rightFront( 6, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// motor for the front(drive)
Motor rightTop(1, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// the right motor on he top, back (drive)
Motor rightBottom(10, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// right motor on the bottom,back (drive)

Motor leftFront(4, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//motor for the front (drive)
Motor leftTop(5, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//the right motor on he top, back (drive)
Motor leftBottom(17, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// left motor on the bottom,back (drive)
  std::shared_ptr<OdomChassisController> drive =
     ChassisControllerBuilder()
    .withMotors({leftFront, leftTop, leftBottom}, {rightFront, rightTop, rightBottom})
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 13.7_in}, okapi::imev5GreenTPR})
    .withSensors(
        ADIEncoder{'A', 'B'}, // left encoder in ADI ports A & B
        ADIEncoder{'C', 'D', true})  // right encoder in ADI ports C & D (reversed)
    .withOdometry({{2.75_in, 7_in}, quadEncoderTPR}) //specifies the tracking wheels dimentions
    .buildOdometry();

  void updateDrive(){
    // drive -> getModel() -> tank(-translate1.power, -translate1.power);
    drive -> getModel() -> tank(controller.getAnalog(ControllerAnalog::leftY), controller.getAnalog(ControllerAnalog::rightY));
    if (controller.getDigital(ControllerDigital::left) == 1){
      leftFront.setBrakeMode(AbstractMotor::brakeMode::hold);
      leftTop.setBrakeMode(AbstractMotor::brakeMode::hold);
      leftBottom.setBrakeMode(AbstractMotor::brakeMode::hold);

      rightFront.setBrakeMode(AbstractMotor::brakeMode::hold);
      rightTop.setBrakeMode(AbstractMotor::brakeMode::hold);
      rightBottom.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
    else if (controller.getDigital(ControllerDigital::right) == 1){
      leftFront.setBrakeMode(AbstractMotor::brakeMode::coast);
      leftTop.setBrakeMode(AbstractMotor::brakeMode::coast);
      leftBottom.setBrakeMode(AbstractMotor::brakeMode::coast);

      rightFront.setBrakeMode(AbstractMotor::brakeMode::coast);
      rightTop.setBrakeMode(AbstractMotor::brakeMode::coast);
      rightBottom.setBrakeMode(AbstractMotor::brakeMode::coast);
    }
  }
