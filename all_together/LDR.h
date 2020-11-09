//Pins required for LDR
int LEDpin = 5;
int LDRpin = A3;

bool LDR(void) {

  int colour, reading, sum;
  float mean, thresh_low;

  int i = 0;

  sum = 0;
  mean = 0;
  thresh_low = 0;
  
//  Move robot back so block will not affect readings

  motor_l->run(FORWARD);
  motor_r->run(FORWARD);
  
  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  delay(1000);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);

//  Takes ambient readings of LDR
  for (i = 0; i <= 20; i+=1) {
  
    reading = analogRead(LDRpin); 

    sum += reading;
  }

//  Find average reading and incorporate error reading, if reading is lower than threshold,block is red
  mean = sum/21;

  thresh_low = mean * 0.96;

//  Moves towards block to take reading
  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  delay(1200);

  motor_l->setSpeed(0);
  motor_r->setSpeed(0);

  delay(1000);
  colour = analogRead(LDRpin);
  delay(500);
  
//If the block is red (ripe), the signal from LDR will be below threshold
  if (colour <= thresh_low) {

    Serial.println("Red");

    return true;
  }

//Otherwise block is blue
  else {

    Serial.println("Blue");

    return false;
  }
}
