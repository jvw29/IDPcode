void avoid(void) {

  float x, y, z, yaw, dt;

  yaw = 0;
  dt = 104.445;

  motor_r->setSpeed(0);
  motor_l->setSpeed(0);

  motor_r->run(FORWARD);
  motor_l->run(FORWARD);

//Left turn (70 degrees instead of 90 due to having to correct for one wheel rotating faster than other)
  while (yaw <= 70) {
    //Serial.println(yaw);
    if (IMU.gyroscopeAvailable()) {
      
      IMU.readGyroscope(x, y, z);

      z += 1.8;
  
      motor_r->setSpeed(150);
      motor_l->setSpeed(150);
      motor_r->run(FORWARD);
      motor_l->run(BACKWARD);

      yaw += z/dt;
  
    }
  }

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

  delay(2500);

  motor_r->setSpeed(0);
  motor_l->setSpeed(0);

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

//Right turn 1
  while (yaw > 0) {

    //Serial.println("right1");
    if (IMU.gyroscopeAvailable()) {
        
      IMU.readGyroscope(x, y, z);
  
       z += 1.8;

       motor_r->setSpeed(150);
       motor_l->setSpeed(150);
       motor_r->run(BACKWARD);
       motor_l->run(FORWARD);

        yaw += z/dt;

       }
   }

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

  delay(3500);

  motor_r->setSpeed(0);
  motor_l->setSpeed(0);

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

  //Right turn 2
  while (yaw > -60) {

  
    if (IMU.gyroscopeAvailable()) {
      IMU.readGyroscope(x, y, z);
  
      z += 1.8;
  
      motor_r->setSpeed(150);
      motor_l->setSpeed(150);
  
      motor_r->run(BACKWARD);
      motor_l->run(FORWARD);

      yaw += z/dt;

    }
  }

  motor_r->run(BACKWARD);
  motor_l->run(BACKWARD);

  //Robot moves forwards until a sensor detects line, then it turns left in order to be orientated in the correct direction
  for (int i=0; i < 100000000; i++) {

    sensorvalue_l = analogRead(sensor_l);
    sensorvalue_c = analogRead(sensor_c);
    sensorvalue_r = analogRead(sensor_r);

    if (sensorvalue_l <= 800 || sensorvalue_c <= 800 || sensorvalue_r <= 800) {

      delay(250);
  
      motor_r->setSpeed(150);
      motor_l->setSpeed(150);

      motor_r->run(FORWARD);
      motor_l->run(BACKWARD);

  
      delay(2000);

      return;
    }

  }
return;
}
