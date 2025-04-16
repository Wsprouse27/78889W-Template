#include "vex.h"
#include "Config.h"
#include "DeviceConfig.h"

using namespace vex;

int ExternalRatio = (MotorGear / WheelGear);
double CircumferenceDegrees = (1 / (pi * WheelDiameter));
double RatioByCircumference = CircumferenceDegrees / ExternalRatio;
double MultiplyInternal = (RatioByCircumference * InternalRatio) * 360;
double Calc = MultiplyInternal;

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void chassis(double DesiredDistance, double DesiredAngle, double ForwardVelocity, double TurnVelocity) {

    double AddDistance = (MultiplyInternal * DesiredDistance);

    double AddTurning = (MultiplyInternal * ((pi * TrackWidth * DesiredAngle) / 360.0));

    int LeftSpeed = ForwardVelocity + TurnVelocity;
    int RightSpeed = ForwardVelocity - TurnVelocity;

    LeftSpeed = clamp(LeftSpeed, -450, 450);
    RightSpeed = clamp(RightSpeed, -450, 450);

    Left.spinFor(forward, AddDistance + AddTurning, degrees, LeftSpeed, rpm);
    Right.spinFor(forward, AddDistance - AddTurning, degrees, RightSpeed, rpm);
}

void drive(double inches1, double velocity){
Brain.Screen.drawRectangle(0, 0, 480, 240, yellow);
Left.setVelocity(velocity, percent);
Right.setVelocity(velocity, percent);
Left.spinFor(forward, inches1*Calc, degrees) && Right.spinFor(forward, inches1*Calc, degrees);
Brain.Screen.drawRectangle(0, 0, 480, 240, green);
}

void smoothdrive(double inches1, double MaxVelocity){
Left.setVelocity(MaxVelocity*.5, percent);
Right.setVelocity(MaxVelocity*.5, percent);
Left.setStopping(coast);
Right.setStopping(coast);
Left.spinFor(forward, inches1*.25*Calc, degrees) && Right.spinFor(forward, inches1*.25*Calc, degrees);
Left.setVelocity(MaxVelocity, percent);
Right.setVelocity(MaxVelocity, percent);
Left.spinFor(forward, inches1*.25*Calc, degrees) && Right.spinFor(forward, inches1*.25*Calc, degrees);
Left.setVelocity(MaxVelocity*.5, percent);
Right.setVelocity(MaxVelocity*.5, percent);
Left.spinFor(forward, inches1*.25*Calc, degrees) && Right.spinFor(forward, inches1*.25*Calc, degrees);
Left.setVelocity(MaxVelocity*.25, percent);
Right.setVelocity(MaxVelocity*.25, percent);
Left.setStopping(hold);
Right.setStopping(hold);
Left.spinFor(forward, inches1*.25*Calc, degrees) && Right.spinFor(forward, inches1*.25*Calc, degrees);
}

void turn(double degrees1, double velocity){
Left.setVelocity(velocity, percent);
Right.setVelocity(velocity, percent);
Left.setStopping(hold);
Right.setStopping(hold);
Left.spinFor(-degrees1*4.5, degrees) && Right.spinFor(degrees1*4.5, degrees);
}

void smoothturn(double degrees1, double MaxVelocity){
    IMU.setHeading(0, degrees);

    Left.setStopping(coast);
    Right.setStopping(coast);
    Left.setVelocity(MaxVelocity*.5, percent);
    Right.setVelocity(MaxVelocity*.5, percent);
    Left.spinFor(-degrees1*4.5*.25, degrees) && Right.spinFor(degrees1*4.5*.25, degrees);
    Left.setVelocity(MaxVelocity, percent);
    Right.setVelocity(MaxVelocity, percent);
    Left.spinFor(-degrees1*4.5*.25, degrees) && Right.spinFor(degrees1*4.5*.25, degrees);
    Left.setVelocity(MaxVelocity*.5, percent);
    Right.setVelocity(MaxVelocity*.5, percent);
    Left.spinFor(-degrees1*4.5*.25, degrees) && Right.spinFor(degrees1*4.5*.25, degrees);
    Left.setVelocity(MaxVelocity*.25, percent);
    Right.setVelocity(MaxVelocity*.25, percent);
    Left.setStopping(hold);
    Right.setStopping(hold);
    Left.spinFor(-degrees1*4.5*.25, degrees) && Right.spinFor(degrees1*4.5*.25, degrees);

    wait(200,msec);
    Left.setVelocity(5, percent);
    Right.setVelocity(5, percent);
    Left.spinFor((-degrees1+IMU.heading(degrees)*4.5),degrees) && Right.spinFor((degrees1-IMU.heading(degrees)*4.5),degrees);
}