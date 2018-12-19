#define enb 13
#define dir 12
#define pul 11

int dTime; // distance between last pul pin changing and this moment
bool pulBool = false; // type of signal to engine (pin pul)
unsigned long microsecondCommonForEngine; // last time of changing signal to pul pin
unsigned long numberOfSpinning = 0; // current number of chenging pul pin

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
  if (isWork && !toUpMove) {
    findNewPeriod();
    changingOfHighAndLow();
    pulBoolSetPin();
  }
  if (toUpMove){
    findNewPeriod();
    changingOfHighAndLow();
    pulBoolSetPin();
    if (positionOfSensor){
      toUpMove = false;
      isWork = false;
    }
  }
}

void findNewPeriod() {
  updateTimeOfSpinning();
  if (newSpin()) {
    setTimeOfSpinning();
    addOneNumberOfSpinning();
  }
}
void updateTimeOfSpinning() {
  dTime = micros() - microsecondCommonForEngine;
}
bool newSpin() {
  if (dTime - delaySpinTime > 0 
    || abs(dTime) > 100000000) // переповнення
    return true;
  return false;
}
void setTimeOfSpinning() {
  microsecondCommonForEngine = getMicros();
}
void addOneNumberOfSpinning(){
  numberOfSpinning++;
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
