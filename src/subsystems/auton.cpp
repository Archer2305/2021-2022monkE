#include "main.h"
#include "drive.hpp"
using namespace okapi;
pros::ADIEncoder rightTracking ('A', 'B', true);
pros::ADIEncoder leftTracking ('C', 'D', false);
float c=17.27875957f;
void turn(float degree){
  if(degree>0){
    while(rightTracking.get_value()<(((3.1415/180)*(14/12)*degree)*(4320/c))){
      /*Im actually a genuis for this omg
      this takes the diameter (between the wheels from the left and right sides) and makes a circle, then it calculates
      the amount of degrees the encoder needs to measure in order to travel that distance x
      */
moveRight(600);
}
  }
  if(degree<0){
      while(leftTracking.get_value()<(((3.1415/180)*14*degree)*(4320/c))){
moveLeft(600);
}
  }
  moveRight(0);
  moveLeft(0);

}
void moveRight(int rpm){ //moves the right side of the drive to the specified rpm, tempory replacement for motor groups
  rightFront.moveVelocity(rpm);
  rightTop.moveVelocity(rpm);
  rightBottom.moveVelocity(rpm);
}
void moveLeft(int rpm){ //moves the left side of the drive to the specified rpm, tempory replacement for motot groups
  leftFront.moveVelocity(rpm);
  leftTop.moveVelocity(rpm);
  leftBottom.moveVelocity(rpm);
}
void move(float feet){
  // drive->driveToPoint({1_ft, 1_ft});

while(rightTracking.get_value()<(feet*(4320/c))){
      moveRight(300);
      moveLeft(300);
}
//stops the motors once the target is met
moveRight(0);
moveLeft(0);
}
