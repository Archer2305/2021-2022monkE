#include "main.h"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/motors.h"
Motor intakeMotor(16, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
void updateIntake(){
    if (controller.getDigital(ControllerDigital::L1) == 1){
    intakeMotor.moveVelocity(600);
    }else if( controller.getDigital(ControllerDigital::L2)==1){
        intakeMotor.moveVelocity(-600);
    }else{
        intakeMotor.moveVelocity(0);
    }
}