//Pins required for photosensors
int sensor_l = A0;
int sensor_c = A1;
int sensor_r = A2;

int sensorvalue_l = 0;
int sensorvalue_c = 0;
int sensorvalue_r = 0;

//Takes reading from line sensors, if below 800, means that sensor is on line, robot corrects itself accordingly to ake sure only centre sensor is on line
void line_follow(void) {

  motor_l->setSpeed(150);
  motor_r->setSpeed(150);

  sensorvalue_l = analogRead(sensor_l);
  sensorvalue_c = analogRead(sensor_c);
  sensorvalue_r = analogRead(sensor_r);


  if (sensorvalue_l >= 900 && sensorvalue_c <= 800 && sensorvalue_r >= 900) {

  
    motor_l->setSpeed(150);
    motor_r->setSpeed(150);

    motor_l->run(BACKWARD);
    motor_r->run(BACKWARD);

    Serial.println("010 Straight");
  }

  else if (sensorvalue_l >= 900 && sensorvalue_c <= 800 && sensorvalue_r <= 800) {


    motor_l->setSpeed(200);
    motor_r->setSpeed(200);
    motor_l->run(BACKWARD);
    motor_r->run(FORWARD);

    Serial.println("011 Turn right");
    }

  else if (sensorvalue_l >= 900 && sensorvalue_c >= 900 && sensorvalue_r <= 800) {

  
    motor_l->setSpeed(200);
    motor_r->setSpeed(200);
    motor_l->run(BACKWARD);
    motor_r->run(FORWARD);

    Serial.println("001 Turn right");
  }

  else if (sensorvalue_l <= 800 && sensorvalue_c <= 800 && sensorvalue_r >= 900) {


    motor_l->setSpeed(200);
    motor_r->setSpeed(200);
    motor_l->run(FORWARD);
    motor_r->run(BACKWARD);

    Serial.println("110 Turn left");
  }

  else if (sensorvalue_l <= 800 && sensorvalue_c >= 900 && sensorvalue_r >= 900) {

    motor_l->setSpeed(200);
    motor_r->setSpeed(200);
    motor_l->run(FORWARD);
    motor_r->run(BACKWARD);

    Serial.println("100 Turn left");
  }

  else if (sensorvalue_l <= 800 && sensorvalue_c <= 900 && sensorvalue_r <= 900) {

    motor_l->setSpeed(200);
    motor_r->setSpeed(200);
    motor_l->run(BACKWARD);
    motor_r->run(FORWARD);

    Serial.println("111 Turn right");
  }

  else if (sensorvalue_l <=800 && sensorvalue_c >=900 && sensorvalue_r <=800) {

    motor_l->setSpeed(200);
    motor_r->setSpeed(200);
    motor_l->run(BACKWARD);
    motor_r->run(FORWARD);  
  }

  else {

    motor_l->setSpeed(150);
    motor_r->setSpeed(150);
    motor_l->run(BACKWARD);
    motor_r->run(BACKWARD);

    Serial.println("not on line");
  }
  return;
}
