#include<Servo.h>

Servo servo_RightMotor;
Servo servo_LeftMotor;

const int ci_Right_Motor=10;
const int ci_Left_Motor=11;
unsigned int ui_Motor_Speed=1700;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ci_Right_Motor,OUTPUT);
  servo_RightMotor.attach(ci_Right_Motor);
  pinMode(ci_Left_Motor,OUTPUT);
  servo_LeftMotor.attach(11);
}

void loop() {
  //unsigned long previousMillis = 0;
  //int interval=100;
  // put your main code her1e, to run repeatedly:
  servo_LeftMotor.writeMicroseconds(ui_Motor_Speed);
  //if(millis() - previousMillis >= interval){
  servo_RightMotor.writeMicroseconds(1700);
  //previousMillis=millis();
  }
  //else
  //servo_RightMotor.write(60);
//}
