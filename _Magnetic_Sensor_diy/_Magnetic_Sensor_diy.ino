void setup(){
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop(){
 int sensorVal=analogRead(A0); 
 Serial.println(sensorVal);
 delay(100);
}

