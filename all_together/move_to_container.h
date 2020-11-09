bool move_to_container(void){

// When robot knows it travelled a distance close to that required to reach container, returns true when it reaches the edge of box i.e all sensors on line
motor_l->setSpeed(150);
motor_r->setSpeed(150);

sensorvalue_l = analogRead(sensor_l);
sensorvalue_c = analogRead(sensor_c);
sensorvalue_r = analogRead(sensor_r);
  
if (sensorvalue_l >= 900 && sensorvalue_c <= 800 && sensorvalue_r >= 900) {

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  return false;

//  Serial.println("010 Straight");
}

else if (sensorvalue_l >= 900 && sensorvalue_c <= 800 && sensorvalue_r <= 800) {

  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

  delay(250);

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  delay(300);

  return false;

//  Serial.println("011 Turn right");
  }

else if (sensorvalue_l >= 900 && sensorvalue_c >= 900 && sensorvalue_r <= 800) {
  
  motor_l->run(BACKWARD);
  motor_r->run(FORWARD);

  return false;

//  Serial.println("001 Turn right");
}

else if (sensorvalue_l <= 800 && sensorvalue_c <= 800 && sensorvalue_r >= 900) {

  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

  return false;

//  Serial.println("110 Turn left");
}

else if (sensorvalue_l <= 800 && sensorvalue_c >= 900 && sensorvalue_r >= 900) {

  motor_l->run(FORWARD);
  motor_r->run(BACKWARD);

  return false;
  
//  Serial.println("100 Turn left");
}

// Meets edge of red box
else if (sensorvalue_l <= 800 && sensorvalue_c <= 800 && sensorvalue_r <= 800) {

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  return true;

//  Serial.println("111 Turn right");
}
else {

  motor_l->run(BACKWARD);
  motor_r->run(BACKWARD);

  return false;
}

return false;
}
