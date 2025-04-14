#include "vex.h"
#include "Config.h"
#include "DeviceConfig.h"

using namespace vex;

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void chassis(double DesiredDistance, double DesiredAngle, double ForwardVelocity, double TurnVelocity) {
    int ExternalRatio = (MotorGear / WheelGear);
    double CircumferenceDegrees = (1 / (pi * WheelDiameter));
    double RatioByCircumference = CircumferenceDegrees / ExternalRatio;
    double MultiplyInternal = (RatioByCircumference * InternalRatio) * 360;
    double AddDistance = (MultiplyInternal * DesiredDistance);

    double AddTurning = (MultiplyInternal * ((pi * TrackWidth * DesiredAngle) / 360.0));

    int LeftSpeed = ForwardVelocity + TurnVelocity;
    int RightSpeed = ForwardVelocity - TurnVelocity;

    LeftSpeed = clamp(LeftSpeed, -450, 450);
    RightSpeed = clamp(RightSpeed, -450, 450);

    Left.spinFor(forward, AddDistance + AddTurning, degrees, LeftSpeed, rpm);
    Right.spinFor(forward, AddDistance - AddTurning, degrees, RightSpeed, rpm);
}
