#include "main.h"
#include "odom.hpp"
#include "drive.hpp"
#include "shooter.hpp"
void aim(){//takes 2 seconds
drive->turnToPoint({16_ft,2.7_ft});
}
void shoot(){//takes 4 seconds
  flywheel.moveVoltage(-12000);
  pros::delay(3000);
  intakeMotor.moveVelocity(-200);
  pros::delay(500);
  intakeMotor.moveVelocity(0);
  pros::delay(500);   
  intakeMotor.moveVelocity(-200);
   intakeMotor.moveVelocity(0);
    
}
void driveForward(double distance) {
    okapi::IterativePosPIDController drivePID = okapi::IterativeControllerFactory::posPID(0.75, 0.01, 0.01);

    const double target = distance;

    drivePID.setTarget(target);

    double orgPosX = drive->getState().x.convert(okapi::foot);
    double orgPosY = drive->getState().y.convert(okapi::foot);

    double distTravelled = 69696.420;

    while (abs(target-distTravelled) >= 0.2) {
        double dx = drive->getState().x.convert(okapi::foot) - orgPosX;
        double dy = drive->getState().y.convert(okapi::foot) - orgPosY;

        distTravelled = sqrt(dx*dx + dy*dy);
        
        double vel = drivePID.step(distTravelled);

        drive -> getModel() -> tank(vel, vel);

        pros::delay(10);
    }

    drivePID.reset();
    drive -> getModel() -> tank(0, 0);
}     
