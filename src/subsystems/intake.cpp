#include "main.h"
void updateIntake(){
Motor intakeMotor(18, true,AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor IntakeMotor(19,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
if(controller.getDigital(ControllerDigital::L2) == 1){
  intakeMotor.moveVelocity(600);
  IntakeMotor.moveVelocity(600);
}else if(controller.getDigital(ControllerDigital::R2)){
  intakeMotor.moveVelocity(-600);
  IntakeMotor.moveVelocity(-600);
}else{
  intakeMotor.moveVelocity(0);
  IntakeMotor.moveVelocity(0);
}
}
