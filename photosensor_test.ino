int sensorl =A0;
int sensorc = A1;
int sensorr = A2;
int sensorvaluel = 0;
int sensorvaluec = 0;
int sensorvaluer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorvaluel = analogRead(sensorl);
  sensorvaluec = analogRead(sensorc);
  sensorvaluer = analogRead(sensorr);
//  Serial.println(sensorvalue);

Serial.print("left sensor ");
Serial.print(sensorvaluel);

Serial.print("centre sensor ");
Serial.print(sensorvaluec);

Serial.print("right sensor ");
Serial.print(sensorvaluer);

Serial.println();
  delay(250);
}
