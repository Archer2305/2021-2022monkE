#include "main.h"
using namespace okapi;
bool Toggle=false;
bool Lock=false;
bool TOGGLE=false;
bool LOCK=false;
pros::ADIDigitalOut leftPiston ('B');
// pros::ADIDigitalOut rightPiston ('H');
int tick=0;
void updateExpantion(){
    
    if(controller.getDigital(ControllerDigital::left) == 1){
        
          if(!Lock){
          Toggle=!Toggle;
        
        Lock=true;
          leftPiston.set_value(Toggle);    
        }
    }
        if(controller.getDigital(ControllerDigital::left)==0){
          Lock=false;
        }


        // if(controller.getDigital(ControllerDigital::right) == 1){
        //   if(!LOCK){
        //   TOGGLE=!TOGGLE;
        // }
        // LOCK=true;
        //   rightPiston.set_value(TOGGLE);    
        // }
        // if(controller.getDigital(ControllerDigital::right)==0){
        //   LOCK=false;
        // }
}