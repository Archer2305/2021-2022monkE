#include "main.h"
void autonomous(){
	start();
}

void initialize(){
	pros::lcd::initialize();
	// pros::ADIEncoder rightTracking ('A', 'B', false);
	// pros::ADIEncoder leftTracking ('C', 'D', true);
	 pros::ADIDigitalOut fourBarClamp('H');
	pros::lcd::set_text(1, "We win theese");
}
	void opcontrol(){
		okapi::Rate rate;
		while (true){
			// updateDrive();
			updateIntake();
			updateLever();
			rate.delay(10_Hz);
		}
	}
