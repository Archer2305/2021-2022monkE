#include "main.h"

using namespace okapi;

extern Controller controller;

struct PID  {
  float kP;
  float kI;
  float kD;
  float target;
  float error;
  float prevError;
  float integral;
  float derivative;
  float power;
  float speed;
};
