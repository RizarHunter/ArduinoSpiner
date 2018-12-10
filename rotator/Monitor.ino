void setupMonitor() {
  //Serial.begin(9600);
  lcd.begin(16, 2);
}

void updateMonitor() {
  //sendToLebtop();
  updateDisplay();
}

void updateDisplay() {
  if ((millisecondCommon + 1000 - lastSendMillisecond) % 1000 > 50) {
    if (spinPerMinute == 0) {
      lcd.setCursor(0, 0);
      lcd.print("PAUSE   ");
      lcd.setCursor(0, 1);
      lcd.print("  PAUSE");
    }
    else {
      lcd.setCursor(0, 0);
      String spinPerMinuteString = " " + String(spinPerMinute)+"  ";
      lcd.print(spinPerMinuteString);
      lcd.setCursor(0, 1);
      lcd.print(" sp/min ");
    }
    lastSendMillisecond = millisecondCommon;
  }
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
