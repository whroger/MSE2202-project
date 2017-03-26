

void setup() {
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);  
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(1));
  Serial.print(" ");
  Serial.print(digitalRead(2));
  Serial.print(" ");
  Serial.print(digitalRead(3));
  Serial.print(" ");  
  Serial.print(digitalRead(4));
  Serial.println(" ");
  delay(500);
}
