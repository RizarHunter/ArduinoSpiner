void setupSound(){
  pinMode(soundPin, OUTPUT);
}

void updateSound(){
  countTimeOfSignal();
  makeSound();
}
void countTimeOfSignal(){
  signalTime--;
  if (signalTime < 0) 
    signalTime = 0;
}
void makeSound(){
  if (signalTime > 0)
    digitalWrite(soundPin, LOW);
  else
    digitalWrite(soundPin, HIGH);
}


void startSignal(){
  signalTime = signalTimeMax;
}

void endSignal(){
  signalTime = 0;
}
