void setupEngine() {
  pinMode(pul, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(enb, OUTPUT);
  digitalWrite(enb, HIGH);
  digitalWrite(enb, LOW);
}

void updateEngine() {
  updateSteper();
}

void updateSteper() {
  if (isWork) {
    findNewPeriod();
    changingOfHighAndLow();
    pulBoolSetPin();
  }
}

void findNewPeriod() {
  updateTimeOfSpinning();
  if (newSpin()) {
    setTimeOfSpinning();
    numberOfSpinning++;
  }
}
void updateTimeOfSpinning() {
  dTime = micros() - microsecondCommonForEngine;
}
bool newSpin() {
  if (dTime - delaySpeed > 0 
    || abs(dTime) > 100000000) // переповнення
    return true;
  return false;
}
void setTimeOfSpinning() {
  microsecondCommonForEngine = micros();
  millisecondLastForEngine = millisecondCommon;
}

void changingOfHighAndLow() {
  if (numberOfSpinning % 2 == 0) {
    pulBool = false;
  }
  else {
    pulBool = true;
  }
}
void pulBoolSetPin() {
  if (pulBool) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
}
