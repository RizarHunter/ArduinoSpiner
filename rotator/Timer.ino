void setupTimer(){
  
}

void updateTimer() {
  getMillis();
  findTime();
}

void getMillis() {
  microsecondCommon = micros() % microsecondMax;
  millisecondCommon = millis();
}

void findTime(){
  millisecondLast = millisecond;
  millisecond = millisecondCommon % 1000;
  second = millisecondCommon / 1000 % 60;
  minute = millisecondCommon / 1000 / 60 % 60;
  hour = millisecondCommon / 1000 / 60 / 60;
}
