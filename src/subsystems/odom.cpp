#include "main.h"
#include "drive.hpp"
using namespace okapi;
	okapi::Rate rate;
pros::ADIEncoder rightTracking ('A', 'B', true);
pros::ADIEncoder leftTracking ('C', 'D', false);
void start(){
  drive->driveToPoint({1_ft, 1_ft});
	okapi::OdomChassisController::getState()
	pros::lcd::set_text(4, " IM gonna kms");
}
