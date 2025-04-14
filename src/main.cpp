#include "vex.h"
#include "DeviceConfig.h"
#include "Config.h"


void DriverControl(void);
void Autonomous(void);
void PreAuton(void);

using namespace vex;

competition Competition;

int main() {
    Competition.autonomous(Autonomous);
    Competition.drivercontrol(DriverControl);

    PreAuton();

    while (true) {
        wait(100, msec);
    }
}
