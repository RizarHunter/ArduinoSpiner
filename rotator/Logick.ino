void setupLogick(){
  
}

void updateLogick(){
  makeSpeed();
  makeTimeDelay();
}

void makeSpeed(){
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

    delaySpeed = (unsigned long)round(1500.0 / abs(spinPerMinute));
  }
}
