#pragma once

extern void chassis(double DesiredDistance, double DesiredAngle, double ForwardVelocity, double TurnVelocity);
extern void drive(double inches1, double velocity);
extern void smoothdrive(double inches1, double MaxVelocity);
extern void turn(double degrees, double velocity);
extern void smoothturn(double degrees, double MaxVelocity);