#include<Servo.h>
#include<ultrasonic.h>
#include<IRremote.h>
#include<Wire.h>

Servo servo_RightMotor;
Servo servo_LeftMotor;
Servo servo_GripMotor;
Servo servo_GripArm;

int stageflag=1;


unsigned int griptimer;
unsigned int irVal;
unsigned int heVal;
unsigned int usVal;

const int GripArm=9;
const int GripMotor=10;
const int LeftMotor=11;
const int RightMotor=12;
const int ultrasonic_Ping=3;
const int ultrasonic_Data=4;
const int ir_sensor=5;
const int he_sensor=A6;

//set up for communication
const int wirecPort=A7;
unsigned int wireVal;

//ir sensor set
IRrecv irrecv(ir_sensor);
decode_results irresults;

//function definitions
void Moveforward();
void ClockwiseSpin();

void setup() {
  Serial.begin(9600);
  //set up ultrasonic sensors
  pinMode(ultrasonic_Ping,OUTPUT);
  pinMode(ultrasonic_Data,INPUT);

  //set up drive motors
  pinMode(RightMotor,OUTPUT);
  servo_RightMotor.attach(RightMotor);
  pinMode(LeftMotor,OUTPUT);
  servo_LeftMotor.attach(LeftMotor);

  //set up grip motor
  pinMode(GripMotor,OUTPUT);
  servo_GripMotor.attach(GripMotor);
  pinMode(GripArm,OUTPUT);
  servo_GripArm.attach(GripArm);
  
  //set up IR & HE sensors
  pinMode(ir_sensor,INPUT);
  irrecv.enableIRIn();//Start the receiver
  pinMode(he_sensor,INPUT);

  //set up wire commucation
  Wire.begin(8);
  
}

void loop(){
  if(stageflag==1)
  {
    usVal=Ping(ultrasonic_Ping,ultrasonic_Data);
    //for the cube
    heVal=analogRead(he_sensor);
    if(heVal>600)
      {
        griptimer=millis();
        stageflag++;
      }
    //for dring straightly
    if(0){
      servo_RightMotor.writeMicroseconds(1680);
      servo_LeftMotor.writeMicroseconds(1680);
    }
    else if(0){
      servo_RightMotor.writeMicroseconds(1680);
      servo_LeftMotor.writeMicroseconds(1680);
    }
    else if(1){
      servo_RightMotor.writeMicroseconds(1680);
      servo_LeftMotor.writeMicroseconds(1680);
    }
  }
  else if(stageflag==2)
  {
    //to be filled
    servo_GripMotor.write(0);
    if(millis()-griptimer>0)
    {
      griptimer=millis();
      stageflag++; 
    }
  }
  else if(stageflag==3)
  {
    //to be filled
    servo_GripArm.write(0);
    if(millis()-griptimer>0)
    {
      griptimer=millis();
      stageflag++; 
    }
  }
  else if(stageflag==4)
  {
    if(irrecv.decode(&irresults))
    {
      irVal=(irresults.value,DEC);
      irrecv.resume();
    }
    if(irVal!=0)
      stageflag++;
    ClockwiseSpin();
  }
  else if(stageflag==5)
  {
    Moveforward();
  }
}

/*void loop() {
  //switch(stageflag){
    if(stageflag==1)
    {
      Moveforward();
      Serial.println("functioning");
    }
    else if(stageflag==2)
    {
      if(irrecv.decode(&irresults))
      {
        irVal=(irresults.value,DEC);
        irrecv.resume();
      }
      Serial.println(irVal);
      delay(200);
      irVal=0;
    }
    else if(stageflag==3)
    {
      heVal=analogRead(he_sensor);
      Serial.println(heVal);
      delay(200);
    }
    else if(stageflag==4)
    {
      usVal=Ping(ultrasonic_Ping,ultrasonic_Data);
      Serial.println(usVal);
    }
    else if(stageflag==5)
    {
      wireVal=Wire.read();  
    }   
}*/


void Moveforward()
{
  servo_RightMotor.writeMicroseconds(1680);
  servo_LeftMotor.writeMicroseconds(1680);
}

void ClockwiseSpin()
{
  servo_RightMotor.writeMicroseconds(0);
  servo_LeftMotor.writeMicroseconds(1350);
}

void function1()  //Move forward and search the cube
{
  Moveforward();
  heVal=analogRead(he_sensor);
  if(heVal>60)
    stageflag++;
}

void function2()
{
  //stage2 to grab the cube
  servo_GripMotor.write(0);
}

void function3()//spin to find the direction of the pyramid
{
  //consider to add another flag to control the spin direction
  ClockwiseSpin();
  irVal=(irresults.value,DEC);
  irrecv.resume();
  if(irVal==1||irVal==2)
    {
      irVal=0;
      stageflag++;
    }
}

void function4() //approach the pyramid while searching
{
  Moveforward();
  irVal=(irresults.value,DEC);
  irrecv.resume();
  irVal--;
  wireVal=Wire.read();
  if((irVal<-1)||(irVal>1&&irVal<3))
  {
    stageflag--;
  }
  else if(wireVal==1)
  {
    stageflag++;
  }
}

void function5()
{
  //capture the pyramid
}
