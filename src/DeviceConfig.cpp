#include "DeviceConfig.h"
#include "Config.h"

using namespace vex;

motor FL(P1);
motor ML(P2);
motor BL(P4);
motor FR(P3);
motor MR(P5);
motor BR(P6);

motor_group Left(FL, ML, BL);
motor_group Right(FR, MR, BR);
