void setupEngine(){
  pinMode(pul, OUTPUT);  
  pinMode(dir, OUTPUT);  
  pinMode(enb, OUTPUT);  
  //digitalWrite(dir, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(enb, LOW);
}

void updateEngine(){
      updateFirstWay();
      //updateSecondWay();
}
void updateFirstWay(){
  if (
    //findNewPeriod();
    millisecondCommon - (delaySpeed / 1000) > numberOfSpinning
    ) {
      spinOneTime();
      numberOfSpinning = millisecondCommon - delaySpeed / 1000;
    }
}
void spinOneTime(){
  if ((int)(millisecondCommon / (delaySpeed / 1000)) % 2 == 0) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
}

bool findNewPeriod() {
  unsigned long t; 
  unsigned long period;
  bool toReturn = false;
  
  //int numberOfPart = microsecondCommon / (microsecondMax / sendPer1Seconds);
  //if (numberOfPart != lastSendMicrosecond) {
  //    toReturn = true;
  //    lastSendMicrosecond = numberOfPart;
  //}
  return toReturn;
}
