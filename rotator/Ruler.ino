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
  if (canChange()){
      startSignal();
      isWork = !isWork;
  }
  isPushedButton = !digitalRead(rulerButtonPin);
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
       counter++;
     } else {
       counter--;
     }
   } 
   aLastState = aState;
}
void updateLimit(){
  int maxSpeed = 23;
  int minSpeed = 0;
  if (counter > maxSpeed) counter = maxSpeed;
  if (counter < minSpeed) counter = minSpeed;
}
