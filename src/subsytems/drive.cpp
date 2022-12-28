#include "main.h"
#include "drive.hpp"
#include "okapi/api/odometry/point.hpp"
using namespace okapi;
Motor rightFront(6, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// motor for the front(drive)
Motor rightTop(4, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// the right motor on he top, back (drive)
Motor rightBottom(5, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// right motor on the bottom,back (drive)

Motor leftFront(18, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//motor for the front (drive)
Motor leftTop(1, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);//the right motor on he top, back (drive)
Motor leftBottom(2, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);// left motor on the bottom,back (drive)

MotorGroup leftDrive ({leftFront,leftTop,leftBottom});
MotorGroup rightDrive({rightFront,rightTop,rightBottom});
//imu 7
// MotorGroup left(leftFront,leftTop,leftBottom);
  std::shared_ptr<OdomChassisController> drive =
     ChassisControllerBuilder()
    .withMotors({leftFront, leftTop, leftBottom}, {rightFront, rightTop, rightBottom})
    .withDimensions(  AbstractMotor::gearset::blue, {{4_in, 15_in}, okapi::imev5BlueTPR})
    .withGains(
        {0.0015, 0,  0.000085}, // distance controller gains
        {0.001, 0,0}, // turn controller gains
        {0.001, 0, 0}  // angle controller gains (helps drive straight)
    )
    // .withSensors(
    //     ADIEncoder{'C', 'D'}, // left encoder in ADI ports A & B
    //     ADIEncoder{'H', 'F', true})  // right encoder in ADI ports C & D (reversed)
    .withOdometry({{4_in, 15_in}, quadEncoderTPR}) //specifies the tracking wheels dimentions
    .buildOdometry();

  void updateDrive(){
      pros::lcd::set_text(1, std::to_string(drive->getState().x.convert(okapi::foot)));
       pros::lcd::set_text(2, std::to_string(drive->getState().y.convert(okapi::foot)));
    // drive -> getModel() -> tank(-translate1.power, -translate1.power);
    drive -> getModel() -> tank(controller.getAnalog(ControllerAnalog::rightY), controller.getAnalog(ControllerAnalog::leftY));
    if (controller.getDigital(ControllerDigital::L1) == 1){
      leftDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
      rightDrive.setBrakeMode(AbstractMotor::brakeMode::hold);
    }
    else if (controller.getDigital(ControllerDigital::L1) == 1){
      leftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
      rightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
    }
  }
