#include "main.h"
#include "drive.hpp"
using namespace okapi;
	okapi::Rate rate;
pros::ADIEncoder rightTracking ('A', 'B', true);
pros::ADIEncoder leftTracking ('C', 'D', false);
float c=17.27875957f;
float ratio=14/12;
float targetR=0;
float targetL=0;
//because the tracking wheels are on the inside of drive, it will make it so that the degrees traveled is larger
//than the actual value, this throws off the equation. to account for this we make a ratio of the radii
//where 14 is the turn radius of the full drive and 12(temporaru) is the turn radius of the tracking wheel
void turn(float degree){
   targetR=(((3.1415/360)*(14/12)*degree)*(4320/c))+rightTracking.get_value();
   targetL=(((3.1415/360)*(14/12)*degree)*(4320/c))+leftTracking.get_value();
  //defining a target so that the total degrees traveled doesnt effect the caluclations
  if(degree>0){
    while(rightTracking.get_value()<targetR){
      /*Im actually a genuis for this omg
      this takes the diameter (between the wheels from the left and right sides) and makes a circle, then it calculates
      the amount of degrees the encoder needs to measure in order to travel that distance x
      */
moveRight(600);
//add  for over/undershoot
}
  }
  if(degree<0){
      while(leftTracking.get_value()<targetL){
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
while(rightTracking.get_value()<(feet*(4320/c))){
      moveRight(300);
      moveLeft(300);
}
//stops the motors once the target is met
moveRight(0);
moveLeft(0);
}

  void moveTo(float x,float y){
    //refer to the desmos https://www.desmos.com/calculator/ocgq6lfaxp
    //updated desmos https://www.desmos.com/calculator/xwelxnljuu
    pros::lcd::set_text(3, "Going inside moveTo");
  //calculate distance
  float d=sqrt((x-0.5833)*(x-0.5833))+(y*y);
  //calculate the degrees
  float De=0;
  //calculate the arc
  float arc=0;
  if((x>0.5833&&y>0)){
  De=-1*((atan((y/(x-0.5833)))*(180/3.1415))+90);
}else{
   De=((atan((y/(x-0.5833))*(180/3.1415))+90));
  }
	arc=(3.1415/180)*(14/12)*De
  //ok now that the initializations are done we can do the logic part of the turn
  if(De==0){

    while(rightTracking.get_value()<(d*(4320/c))){

          moveRight(300);
          moveLeft(300);
          rate.delay(10_Hz);
    }
    //stops the motors once the target is met
    // moveRight(0);
    // moveLeft(0);
  }else if(De>0){
  while(rightTracking.get_value()<((3.1415/180)*(14/12)*De)){
  pros::lcd::set_text(4, "Entered while loop");
    moveRight((d/((3.1415/180)*(14/12)*De)+d));
    moveLeft(600);
    rate.delay(10_Hz);

  }
  }else if(De<0){
    pros::lcd::set_text(5, "Entered if loop");
    while(leftTracking.get_value()<((3.1415/180)*(14/12)*De)){
pros::lcd::set_text(4, "Entered while loop");
      moveLeft((d/((3.1415/180)*(14/12)*De)+d));
      moveRight(600);
      rate.delay(10_Hz);
    }
}

// stops motors once target is met
moveRight(0);
moveLeft(0);
}
