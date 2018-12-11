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
  something2();
  pulBoolSetPin2();
}
bool findNewPeriod2() {
  lastTimeOfChaging = thousand * millisecondCommon / delaySpeed + microsecondCommon % thousand / delaySpeed;

  if (lastEngineSpinTime != lastTimeOfChaging) {
    lastEngineSpinTime = lastTimeOfChaging;
    numberOfSpinning++;
    return true;
  }
  else return false;
}
void something2() {
  if (findNewPeriod2() && numberOfSpinning % 2 == 0) {
    delayCounter = microsecondCommon % 1000;
    delayCounterMillis = millisecondCommon;
    pulBool = false;
  }
  else {
    if (pulBool) {
      
    }
    else {
      if (microsecondCommon % 1000 + millisecondCommon * 1000 -
          delayCounter % 1000 - delayCounterMillis * 1000
          > delayStop) {
        pulBool = true;
      }
    }
  }
}
void pulBoolSetPin2() {
  if (pulBool) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
}



void updateSteperThirdVariant() {
  something3();
  pulBoolSetPin3();
}
bool findNewPeriod3() {
  unsigned long t = 1000 * millisecondCommon + microsecondCommon % 1000;
  numberOfSpinning = (int)(t / delaySpeed);

  if (lastEngineSpinTime != numberOfSpinning) {
    lastEngineSpinTime = numberOfSpinning;
    return true;
  }
  else return false;
}
void something3() {
  if (findNewPeriod3() && numberOfSpinning % 2 == 0) {
    delayCounter = microsecondCommon % 1000;
    delayCounterMillis = millisecondCommon;
    pulBool = false;
  }
  else {
    if (pulBool) {
      
    }
    else {
      if (microsecondCommon % 1000 + millisecondCommon * 1000 -
          delayCounter % 1000 - delayCounterMillis * 1000
          > delayStop) {
        pulBool = true;
      }
    }
  }
}
void pulBoolSetPin3() {
  if (pulBool) digitalWrite(pul, HIGH);
  else digitalWrite(pul, LOW);
}
