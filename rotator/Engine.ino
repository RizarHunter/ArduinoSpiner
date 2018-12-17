void setupEngine() {
  pinMode(pul, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(enb, OUTPUT);
  //digitalWrite(dir, HIGH);
  digitalWrite(enb, HIGH);
  digitalWrite(enb, LOW);
}

void updateEngine() {
  updateSteperSecondVariant();
  //updateSteperThirdVariant();
}


void updateSteperSecondVariant() {
  changingOfHighAndLow();
  pulBoolSetPin();
}
void changingOfHighAndLow() {
  if (isWork && findNewPeriod()) {
    if (numberOfSpinning % 2 == 0){
      pulBool = false;
    }
    else {
      pulBool = true;
    }
  }
}
bool findNewPeriod() {
  lastTimeOfChanging = millisecondCommon * thousand / delaySpeed 
    + microsecondCommon / delaySpeed % thousand;

  if (lastEngineSpinTime != lastTimeOfChanging) {
    lastEngineSpinTime = lastTimeOfChanging;
    numberOfSpinning++;
    return true;
  }
  else {
    lastEngineSpinTime = lastTimeOfChanging;
    return false;
  }
}

void pulBoolSetPin() {
  if (pulBool) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
}
