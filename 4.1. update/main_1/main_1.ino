#include<Wire.h>

unsigned int Val1;
unsigned int Val2;
unsigned int Val3;
unsigned int Val4;
bool Flag=0;

void setup() {
  Wire.beginTransmission(8);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);  
  Serial.begin(9600);
}

void loop() {
  Val1=digitalRead(1);
  Val2=digitalRead(2);
  Val3=digitalRead(3);
  Val4=digitalRead(4);
  Serial.print(Val1);
  Serial.print(" ");
  Serial.print(Val2));
  Serial.print(" ");
  Serial.print(Val3);
  Serial.print(" ");  
  Serial.print(Val4));
  Serial.println(" ");
  //delay(300);
  if(Val1==0&&Val2==0&&Val3==0&&Val4==0)
    Wire.write(1);
}
