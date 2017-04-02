#pragma once

#define lnormalspeed 1700
#define lslowspeed 1650
#define lfastspeed 1750
#define rnormalspeed 1700
#define rlowspeed 1650
#define rastspeed 1750
#define lbackspeed 1350
#define rbackspeed 1350

#include <Servo.h>

void MoveFoward(int LeftM, int RightM) {
	servo_LeftM.writeMicroseconds(lnormalspeed);
	servo_RightM.writeMicroseconds(rnormalspeed);
}

void MoveBackward(int LeftM, int RightM) {
	servo_LeftM.writeMicroseconds(lbackspeed);
	servo_RightM.writeMicroseconds(rbackspeed);
}

void ClockwiseSpin(int LeftM, int RightM) {
	servo_LeftM.writeMicroseconds(0);
	servo_RightM.writeMicroseconds(rbackspeed);
}

void CounterClockwiseSpin(int LeftM, int RightM) {
	servo_LeftM.writeMicroseconds(lbackspeed);
	servo_RightM.writeMicroseconds(0);
}