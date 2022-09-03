#include "main.h"

using namespace okapi;


Motor rightFront(16, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// motor for the front(drive)
Motor rightTop(13, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// the right motor on he top, back (drive)
Motor rightBottom(12, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// right motor on the bottom,back (drive)

Motor leftFront(5, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//motor for the front (drive)
Motor leftTop(1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//the right motor on he top, back (drive)
Motor leftBottom(2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// left motor on the bottom,back (drive)

// MotorGroup left(leftFront,leftTop,leftBottom);
  std::shared_ptr<OdomChassisController> drive =
     ChassisControllerBuilder()
    .withMotors({leftFront, leftTop, leftBottom}, {rightFront, rightTop, rightBottom})
    .withDimensions(AbstractMotor::gearset::blue, {{4_in, 13.7_in}, okapi::imev5GreenTPR})
    // .withSensors(
    //     ADIEncoder{'G', 'F'}, // left encoder in ADI ports A & B
    //     ADIEncoder{'E', 'D', true})  // right encoder in ADI ports C & D (reversed)
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
