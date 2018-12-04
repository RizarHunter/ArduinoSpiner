void setupLogick(){
  
}

void updateLogick(){
  makeSpeed();
  makeTimeDelay();
}

void makeSpeed(){
  int maxSpeed = 22;
  if (counter > maxSpeed) counter = maxSpeed;
  if (counter < -maxSpeed) counter = -maxSpeed;
  if (counter == 0) { spinPerMinute = 0; return; }

  if (abs(counter) <= 20){
    spinPerMinute = counter/10.0;
  }
  else{
    spinPerMinute = (abs(counter)-19) * 2 * counter/abs(counter);
  }
}

void makeTimeDelay(){
  if (spinPerMinute == 0) {
    digitalWrite(enb, HIGH);
    delaySpeed = 0;
  }
  else {
    digitalWrite(enb, LOW);
    
    if (spinPerMinute > 0) digitalWrite(dir, HIGH);
    else digitalWrite(dir, LOW);

    delaySpeed = ((60.0f / abs(spinPerMinute)) * 1200)/1000;
  }
}
