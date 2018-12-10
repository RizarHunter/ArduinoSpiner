void setupRuler(){
  pinMode(rulerButtonPin, INPUT);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
   
  aLastState = digitalRead(outputA);  
}

void updateRuler(){
  updateButton();
  updateRing();
}

void updateButton(){ }

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
