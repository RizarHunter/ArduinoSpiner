void setupMonitor() {
  //Serial.begin(9600);
  lcd.begin(16, 2);
}

void updateMonitor() {
  //sendToLebtop();
  updateDisplay();
}

void updateDisplay() {
  if (sendTimerDataToMonitor()) {
    if (spinPerMinute == 0) {
      lcd.setCursor(0, 0);
      lcd.print("PAUSE   ");
      lcd.setCursor(0, 1);
      lcd.print("  PAUSE");
    }
    else {
      lcd.setCursor(0, 0);
      lcd.print(" " + String(spinPerMinute)+"  ");
      lcd.setCursor(0, 1);
      lcd.print(delaySpeed/*" sp/min "*/);
    }
  }
}
bool sendTimerDataToMonitor() {
  bool toReturn = false;
  int numberOfPart = microsecondCommon / (microsecondMax / sendPer1Seconds);
  if (numberOfPart != lastSendMicrosecond) {
      toReturn = true;
      lastSendMicrosecond = numberOfPart;
  }
  return toReturn;
}

void sendToLebtop() {
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
