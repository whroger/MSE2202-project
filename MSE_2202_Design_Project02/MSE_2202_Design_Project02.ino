#include <Servo.h>
#include <EEPROM.h>
#include <uSTimer2.h>
#include <CharliePlexM.h>
#include <Wire.h>
#include <I2CEncoder.h>

// FOR LEDS NUMBER 1 THROUGH 12
const int ci_Charlieplex_LED1 = 4;
const int ci_Charlieplex_LED2 = 5;
const int ci_Charlieplex_LED3 = 6;
const int ci_Charlieplex_LED4 = 7;
int LED = -2;
int stepComplete = 0;

// Begin Switch
int DPDTswitch = 3;
int timerCounter = 0;
int timer1 = 0;
int timer2 = 0;
int counter = 0;


// Motors
Servo servo_RightMotor;
Servo servo_LeftMotor;
const int ci_Right_Motor = 8;
const int ci_Left_Motor = 9;




const int ir = 0;

void setup() {
  Serial.begin(2400);
  CharliePlexM::set(ci_Charlieplex_LED1, ci_Charlieplex_LED2,ci_Charlieplex_LED3,ci_Charlieplex_LED4);
  pinMode(ci_Right_Motor, OUTPUT);
  servo_RightMotor.attach(ci_Right_Motor);
  pinMode(ci_Left_Motor, OUTPUT);
  servo_LeftMotor.attach(ci_Left_Motor);
  pinMode(DPDTswitch, INPUT);


  
  pinMode(ir,INPUT);
}

void loop() {


Serial.print(" IR Sensor: "); 
Serial.available(); 
Serial.println(Serial.read());


  CharliePlexM::Write(LED, 1);
  if (stepComplete == 1) {
    CharliePlexM::Write(LED, 0); // TO HAVE THE LEDS SWITCH HORIZONTALLY AFTER EACH STEP
    LED = LED + 3;
    if (LED >= 13) {
      LED = LED - 14;
      if (LED < 1) {
        LED = LED + 3;
      }
    }
    stepComplete = 0; // RESET STEP COMPLETE CHECK
    timerCounter = 0; // RESET TIMERS
    timer1 = 0;
    timer2 = 0;
    counter++; // NEXT STEP
  }

/*******************************************/
if (counter == 0) {
  stepComplete = 1;
}
if (counter == 1 && digitalRead(DPDTswitch) == LOW) {
  if (timerCounter == 0) {
    timerCounter++;
    timer1 = millis();
  }
  timer2 = millis();
  if (timer2 - timer1 >= 3000) {
    stepComplete = 1;
  }
}
/*******************************************/

}


