#include "main.h"
void autonomous(){
	okapi::Rate rate;
	while (true) {
	pros::lcd::set_text(2, "auton function running");
	moveTo(2.0,2.0);
	rate.delay(10_Hz);

}

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
