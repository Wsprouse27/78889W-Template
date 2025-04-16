#include "vex.h"
#include "DrivetrainConfig.h"
#include "DeviceConfig.h"

void Skills() {

}

void Red1() {

}

void Red2() {

}

void Blue1() {

}

void Blue2() {

}

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