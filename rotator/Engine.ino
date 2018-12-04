void setupEngine(){
  pinMode(pul, OUTPUT);  
  pinMode(dir, OUTPUT);  
  pinMode(enb, OUTPUT);  
  //digitalWrite(dir, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(enb, LOW);
}

void updateEngine(){
  if (isWork){
      updateFirstWay();
    
      //updateSecondWay();
  }
}

void updateFirstWay(){
  if (millisecondCommon - delaySpeed > numberOfSpinning){
      spinOneTime();
      numberOfSpinning = millisecondCommon - delaySpeed;
    }
}
void spinOneTime(){
  if ((int)(millisecondCommon / delaySpeed) % 2==0) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
  /*spinSide != spinSide;
  if (spinSide) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);*/
}

void updateSecondWay(){
  delayMicroseconds(delaySpeed);
  digitalWrite(pul, HIGH);
  delayMicroseconds(delaySpeed);
  digitalWrite(pul, HIGH);
}
