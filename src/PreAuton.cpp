#include "vex.h"
#include "Configs/Config.h"
#include "Configs/DeviceConfig.h"

using namespace vex;

void PreAuton(void) {


    IMU.calibrate();
    while (IMU.isCalibrating()) {
        wait(100, msec);
    }
    Controller.rumble("..--");
}
