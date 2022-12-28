#include "main.h"
#include "shooter.hpp"
bool toggle=false;
bool lock=false;
Motor flywheel(10,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
void updateShooter(){

if(controller.getDigital(ControllerDigital::R2) == 1){
   if(!lock){
        toggle=!toggle;
      }
      lock=true;
        flywheel.moveVoltage(-12000);
      }
      if(controller.getDigital(ControllerDigital::R2)==0){
        lock=false;
      }
      if(toggle==false){
         flywheel.moveVelocity(0);
      }
  
}
 /*
 
 */

   

       