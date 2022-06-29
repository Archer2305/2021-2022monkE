#include "main.h"
using namespace okapi;
extern Motor rightFront;
extern Motor rightTop;
extern Motor rightBottom;
extern Motor leftFront;
extern Motor leftTop;
extern Motor leftBottom;
extern std::shared_ptr<ChassisController> drive;
extern Controller controller;
void updateDrive();
