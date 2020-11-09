int trigPin = 13;
int echoPin = 12;

bool ultrasonic(void) {
  int sum = 0;
  int duration;
  int distance;
  float mean = 0;

//  Takes rolling average of last four ultrasound redings
  for (int i =0; i<=3; i++) {
    digitalWrite(trigPin, LOW);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration*0.034/2;

    sum += distance;
  }

  mean = sum/4;

//Range of values returned if obstacle was detected
  if (3 <= mean && mean <= 12) {

    return true;
  }
  
  else {
    
    return false;
  }
  
}
