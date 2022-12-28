#include "main.h"
#include "auton.hpp"
#include "drive.hpp"
#include "shooter.hpp"
// #include "okapi/impl/device/controllerUtil.hpp"
int route=1; //0 is no roler, 1 is roler
bool LoCK=false;
void updateAuton(){
  
    if(route==1){
      flywheel.moveVelocity(-600);
      leftDrive.moveVelocity(-10);
      rightDrive.moveVelocity(-10);
      intakeMotor.moveVelocity(600);
      pros::delay(500);                
      intakeMotor.moveVelocity(0);  
      leftDrive.moveVelocity(0);
      rightDrive.moveVelocity(0);
      pros::delay(1000);
      driveForward(1.5);
       pros::delay(1500);
      intakeMotor.moveVelocity(-600);
  aim();
  shoot();
  // Lock=true; 
    }else{
      /*
1,0
-1.325,-3.359
1,-1

*/
    drive->driveToPoint({-2.166_ft,0_ft});
    drive->turnAngle(-90*okapi::degree);
    drive->driveToPoint({0_ft,1_ft});
    drive->turnAngle(-90*okapi::degree);
    drive->driveToPoint({1_ft,-1_ft});
  }
}
void stop(){
  if(LoCK==true){
    rightFront.moveVelocity(0);
rightTop.moveVelocity(0);
rightBottom.moveVelocity(0);
leftFront.moveVelocity(0);
leftTop.moveVelocity(0);
leftBottom.moveVelocity(0);
intakeMotor.moveVelocity(0);
flywheel.moveVelocity(0);
  }
  Lock=false;
}

