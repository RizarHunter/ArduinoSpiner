#define soundPin 9

int signalTimeMax = 120; // max time of signal in cycles 
int signalTime = signalTimeMax; // time of signal in cycles of program

void setupSound(){
  pinMode(soundPin, OUTPUT);
}

void updateSound(){
  countTimeOfSignal();
  makeSound();
}
void countTimeOfSignal(){
  if (signalTime < 0) 
    signalTime = 0;
  else
    signalTime--;
}
void makeSound() {
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
