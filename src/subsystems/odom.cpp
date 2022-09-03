#include "main.h"
#include "drive.hpp"
using namespace okapi;
	okapi::Rate rate;
// pros::ADIEncoder rightTracking ('A', 'B', true);
// pros::ADIEncoder leftTracking ('C', 'D', false);
	pros::Imu LeftInertial(1);
pros::Imu RightInertial(2);

void updateOdom(){
	////storing  coords as feet
	float y=drive->getState().x.convert(okapi::foot);
  float x=drive->getState().y.convert(okapi::foot);
	// float y=1.convert
	//the variable names ar reversed to return it into a cartesian plane.
	int xTiles=floor(x/2);
	int yTiles=floor(y/2);
	//start calculaing the degress needed to turn
	float target=45;
	 if(x<0.5833){
		target=atan(y/x)+90;
	}
	if(x>0.5833){
		target=-1*(atan(y/x))+90;
	}
	if(controller.getDigital(ControllerDigital::R1) == 1){
	// drive->turnToAngle((target* okapi::degree));
	turn(target);
}

}
void turn (float target){

	if(target<90){
		while(LeftInertial.get_roll()<target-5){ //minus 5 as a temp replacement for pid
		leftFront.setBrakeMode(AbstractMotor::brakeMode::hold);
		leftTop.setBrakeMode(AbstractMotor::brakeMode::hold);
		leftBottom.setBrakeMode(AbstractMotor::brakeMode::hold);

		rightFront.setBrakeMode(AbstractMotor::brakeMode::hold);
		rightTop.setBrakeMode(AbstractMotor::brakeMode::hold);
		rightBottom.setBrakeMode(AbstractMotor::brakeMode::hold);
	}
}else{
	while(RightInertial.get_roll()<target-5){
		leftFront.setBrakeMode(AbstractMotor::brakeMode::coast);
		leftTop.setBrakeMode(AbstractMotor::brakeMode::coast);
		leftBottom.setBrakeMode(AbstractMotor::brakeMode::coast);

		rightFront.setBrakeMode(AbstractMotor::brakeMode::coast);
		rightTop.setBrakeMode(AbstractMotor::brakeMode::coast);
		rightBottom.setBrakeMode(AbstractMotor::brakeMode::coast);
	}
}
}
