#include "vex.h"
#include "DeviceConfig.cpp"
#include "DriverControl.cpp"
#include "Auton.cpp"
#include "PreAuton.cpp"

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
