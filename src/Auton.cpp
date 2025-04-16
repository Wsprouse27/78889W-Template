#include "vex.h"
#include "Configs/DrivetrainConfig.h"
#include "Configs/DeviceConfig.h"
#include "Autons/Auton.h"

void Autonomous(void) {
    if (AutoSelector.angle() < 50) {
     Red1();
    }
    else if (50 < AutoSelector.angle() < 100) {
     Red2();
    }
    else if (100 < AutoSelector.angle() < 150) {
     Skills();
    }
    else if (150 < AutoSelector.angle() < 200) {
     Blue1();
    }
    else if (AutoSelector.angle() > 200) {
     Blue2();
    }
 }