int interrupter_pin = A4;

float distance_forward() {

  int interrupter = analogRead(interrupter_pin);

  if (interrupter > 124) {

    distance_travelled =+ 4.56;
  }

  return distance_travelled;
  
}

float distance_backward() {

  int interrupter = analogRead(interrupter_pin);

  if (interrupter > 124) {

    distance_travelled =- 4.56;
  }

  return distance_travelled;
  
}
