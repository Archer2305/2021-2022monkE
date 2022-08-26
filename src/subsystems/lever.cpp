#include "main.h"
using namespace okapi;

pros::ADIDigitalOut leverPiston ('H');
bool toggle=false;

  	void updateLever(){

      if(controller.getDigital(ControllerDigital::L1) == 1){
        toggle=!toggle;
        leverPiston.set_value(toggle);
      }

}
