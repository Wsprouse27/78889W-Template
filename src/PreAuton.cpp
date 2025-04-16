#include "vex.h"
#include "Config.h"
#include "DeviceConfig.h"

using namespace vex;

void PreAuton(void) {


    IMU.calibrate();
    while (IMU.isCalibrating()) {
        wait(100, msec);
    }
    Controller.rumble("..--");
}
