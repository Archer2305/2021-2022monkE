#include "main.h"
void autonomous(){
	move();
}
void initialize(){
	pros::lcd::initialize();
	pros::lcd::set_text(1, "L bozo");
}
void opcontrol(){
	okapi::Rate rate;
	while (true){
		updateDrive();
		rate.delay(10_Hz);
	}
}
