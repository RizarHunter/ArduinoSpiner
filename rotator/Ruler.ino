void setupRuler(){
  pinMode(rulerButtonPin, INPUT);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
   
  aLastState = digitalRead(outputA);  
}

void updateRuler(){
  //updateButton();
  updateRing();
}

void updateButton(){
  if (/*lastPush == false && */lastPush != digitalRead(rulerButtonPin)){
    isWork = !isWork;
  }
  lastPush = digitalRead(rulerButtonPin);
}

void updateRing(){
  aState = digitalRead(outputA);
   if (aState != aLastState){     
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
   } 
   aLastState = aState;
}
