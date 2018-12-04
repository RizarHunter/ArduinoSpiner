void setupMonitor(){
  Serial.begin(9600);
}

void updateMonitor(){
  sendToLebtop();
}

void sendToLebtop(){
  if ((second + 60 - lastSendSecond) % 60 == 1) {
    Serial.print("counter: ");
    Serial.print(counter);
    Serial.print(" spinPer: ");
    Serial.print(spinPerMinute);
    Serial.print(" delay:"); 
    Serial.print(delaySpeed);
    Serial.print(" spin:");
    Serial.print(spins);
    Serial.print(" number:");
    Serial.print((int)(numberOfSpinning));
    Serial.print(" millis:");
    Serial.println(millisecondCommon);
    
    
    lastSendSecond = second;
  }
}
