#define rulerButtonPin 53
#define outputA 49
#define outputB 51

bool isPushedButton = false;
unsigned long millisecondLastPushButton;

unsigned long millisecondOfPushingNeed = 10000;

int aState;
int aLastState;
int maxValue = 23;
int minValue = 0;

void setupRuler(){
  pinMode(rulerButtonPin, INPUT_PULLUP);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
   
  aLastState = digitalRead(outputA);  
}

void updateRuler(){
  updateButton();
  updateRing();
}

void updateButton(){ 
  toUp();
  
  if (canChange()){
      startSignal();
      isWork = !isWork;
  }
  isPushedButton = !digitalRead(rulerButtonPin);
}
void toUp(){
  if (!toUpMove && !digitalRead(rulerButtonPin)){
    millisecondOfPushing++;
    if (millisecondOfPushing > millisecondOfPushingNeed){
      toUpMove = true;
      isWork = true;
      startSignal(420);
    }
  }
  else {
    millisecondOfPushing = 0;
  }
}
bool canChange(){
  if (isPushedButton == !digitalRead(rulerButtonPin)) return false;
  if (digitalRead(rulerButtonPin)) return false;
  if (millisecondCommon - millisecondLastPushButton > 400ul) {
    millisecondLastPushButton = millisecondCommon;
    return true;
  }
  return false;
}



void updateRing(){
  if (!isWork) {
    updateCounterValue();
    updateLimit();
  }
}
void updateCounterValue(){
  aState = digitalRead(outputA);
   if (aState != aLastState){     
     if (digitalRead(outputB) != aState) { 
       positionOfEncoder++;
     } else {
       positionOfEncoder--;
     }
   } 
   aLastState = aState;
}
void updateLimit(){
  if (positionOfEncoder > maxValue) positionOfEncoder = maxValue;
  if (positionOfEncoder < minValue) positionOfEncoder = minValue;
}
