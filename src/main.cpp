#include "main.h"
void autonomous(){
	move(1);
}
void initialize(){
	pros::lcd::initialize();
	pros::ADIEncoder rightTracking ('A', 'B', false);
	pros::ADIEncoder leftTracking ('C', 'D', true);
	pros::lcd::set_text(1, "L bozo");
}
void opcontrol(){
	okapi::Rate rate;
	while (true){
		updateDrive();
		updateIntake();
		rate.delay(10_Hz);
	}
}
