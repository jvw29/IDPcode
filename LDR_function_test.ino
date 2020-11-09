//int LEDpin = 5;
int LDRpin = A3;

#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Wire.h>
#include <Arduino_LSM6DS3.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motor_l = AFMS.getMotor(2);
Adafruit_DCMotor *motor_r = AFMS.getMotor(1);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

AFMS.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("hello");
  int colour, reading, sum;
  float mean, thresh_low;
//Controls strength of signal from pin

  int i = 0;

///  digitalWrite(LEDpin, HIGH);

  sum = 0;
  mean = 0;
  thresh_low = 0;
  
///  Move robot back so block will not affect readings


  /*motor_l->run(FORWARD);
  motor_r->run(FORWARD);
  
  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  

  Serial.println("Move backward");
  delay(1000);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);*/

//  Takes ambient readings of LDR
  for (i = 0; i <= 20; i+=1) {
  
    reading = analogRead(LDRpin); 

//    Serial.println(reading);
//    delay(1000);
    sum += reading;
//    Serial.println(sum);
  }

//  Find average reading and incopororate error reading, any higher means the block is blue
  mean = sum/21;

  thresh_low = mean * 0.98;

  Serial.print("Threshold is");
  Serial.print(thresh_low);
  Serial.println();

  delay(5000);
//  Moves towards block to take reading
  /*motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  Serial.println("Move forward");
  delay(1000);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);*/

//  delay(1000);
  colour = analogRead(LDRpin);
  Serial.print("reading is");
  Serial.print(colour);
  Serial.println();
  
//If the fruit is blue (unripe), the signal from the amplifier will be high
  if (colour <= thresh_low) {

    Serial.println("Red");

//    digitalWrite(LEDpin,LOW);
//    return true;
  }

//If the fruit is red (ripe), the signal from the amplifier will bev low) 
  else {

    Serial.println("Blue");

//    return false;
//    digitalWrite(LEDpin,LOW);

}
}
