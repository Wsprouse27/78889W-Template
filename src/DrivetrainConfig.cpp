#include "vex.h"
#include "Config.cpp"
#include "DeviceConfig.cpp"
#include <algorithm>
using namespace vex;

void chassis(double DesiredDistance, double DesiredAngle, double ForwardVelocity, double TurnVelocity) {
    //Forward Stuff
int ExternalRatio = (MotorGear/WheelGear);
int CircumfrenceDegrees = (1/(pi*WheelDiameter));
int RatiobyCircumfrence = CircumfrenceDegrees/ExternalRatio;
int MultiplyInternal = (RatiobyCircumfrence*InternalRatio)*360;
int AddDistance = (MultiplyInternal*DesiredDistance);

    //Turn Stuff
int UptoTurning = MultiplyInternal;
int AddTurning = (UptoTurning*((pi*TrackWidth*DesiredAngle)/360.0));

    //Velocity Stuff
int LeftSpeed = ForwardVelocity + TurnVelocity;
int RightSpeed = ForwardVelocity - TurnVelocity;
int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
LeftSpeed = clamp(LeftSpeed, -450, 450);
RightSpeed = clamp(RightSpeed, -450, 450);

Left.spinFor(forward,AddDistance+AddTurning,degrees,LeftSpeed,rpm);
Right.spinFor(forward,AddDistance-AddTurning,degrees,RightSpeed,rpm);
}