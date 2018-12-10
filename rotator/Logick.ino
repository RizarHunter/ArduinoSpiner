void setupLogick(){
  
}

void updateLogick(){
  makeSpeed();
  makeTimeDelay();
}

void makeSpeed(){
  int maxSpeed = 100;
  if (counter > maxSpeed) counter = maxSpeed;
  if (counter < -maxSpeed) counter = -maxSpeed;
  
  spinPerMinute = counter / 10.0;
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

    delaySpeed = (60.0f / abs(spinPerMinute)) * 1200;
    //delaySpeed = /*60.0f*1200/1000*/ 72.0f / abs(spinPerMinute);
  }
}
