#include<Servo.h>

Servo servo_RightMotor;
Servo servo_LeftMotor;

const int ci_Right_Motor=10;
const int ci_Left_Motor=11;
unsigned int ui_Motor_Speed=1700;   // the two motors performed diffrently

void setup() {
  Serial.begin(9600);
  pinMode(ci_Right_Motor,OUTPUT);
  servo_RightMotor.attach(ci_Right_Motor);
  pinMode(ci_Left_Motor,OUTPUT);
  servo_LeftMotor.attach(ci_Left_Motor);
}

void loop() {
  servo_LeftMotor.writeMicroseconds(ui_Motor_Speed);
  servo_RightMotor.writeMicroseconds(ui_Motor_Speed);
}

