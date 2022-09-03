#include "main.h"
// void autonomous(){
// 	start();
// }

void initialize(){
	pros::lcd::initialize();
	// pros::ADIEncoder rightTracking ('G', 'F', false);
	// pros::ADIEncoder leftTracking ('E', 'D', true);
	pros::Imu LeftInertial(1);
	pros::Imu RightInertial(2);
	 pros::ADIDigitalOut fourBarClamp('H');
	pros::lcd::set_text(1, "We win theese");
}
	void opcontrol(){
		okapi::Rate rate;
		while (true){
			updateDrive();
			updateIntake();
			updateLever();
			updateOdom();
			rate.delay(10_Hz);
		}
	}
