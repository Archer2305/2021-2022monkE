#include "main.h"
void updateFlywheel(){
Motor flywheel(0, true,AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
if(controller.getDigital(ControllerDigital::R1) == 1){
  intakeMotor.moveVelocity(600);

}else{
  intakeMotor.moveVelocity(0);
}
}
