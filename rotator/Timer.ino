void setupTimer(){
  
}

void updateTimer() {
  getMillis();
}

void getMillis() {
  microsecondCommon = micros();
  millisecondCommon = millis();
}

unsigned long getMicros(){
  return micros();
}
