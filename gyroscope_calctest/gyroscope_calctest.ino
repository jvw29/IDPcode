#include <Arduino_LSM6DS3.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(IMU.gyroscopeSampleRate());

delay(250);

// Gyro baud = 104

//Euler



float x, y, z;

float degree;

degree = 0;

 if (IMU.gyroscopeAvailable()) {
  
    while (degree < 90) {
      
     float dt = 104.445;
     
     IMU.readGyroscope(x, y, z);

     z = z +1.8;
     degree = degree+(z/104);

     Serial.println(degree);
}
 }
}
