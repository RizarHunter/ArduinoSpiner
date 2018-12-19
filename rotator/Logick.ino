void setupLogick(){
  
}

void updateLogick(){
  makeSpeed();
  makeTimeDelay();
}

void makeSpeed(){
  switch (counter/2){
    case 0 : { spinPerMinute = 4; delaySpeed = 200; } break;
    case 1 : { spinPerMinute = 2; delaySpeed = 320; } break;
    case 2 : { spinPerMinute = 1.3; delaySpeed = 600; } break;
    case 3 : { spinPerMinute = 1; delaySpeed = 900; } break;
    
    case 4 : { spinPerMinute = 0.8; delaySpeed = 1200; } break;
    case 5 : { spinPerMinute = 0.66; delaySpeed = 1400; } break;
    case 6 : { spinPerMinute = 0.5; delaySpeed = 1800; } break;
    case 7 : { spinPerMinute = 0.4; delaySpeed = 2400; } break;
    
    case 8 : { spinPerMinute = 0.33; delaySpeed = 2800; } break;
    case 9 : { spinPerMinute = 0.25; delaySpeed = 4000; } break;
    case 10: { spinPerMinute = 0.16; delaySpeed = 6000; } break;
    case 11: { spinPerMinute = 0.12; delaySpeed = 8000; } break;

    default : { spinPerMinute = 2; delaySpeed = 300; } break;
  }
}

void makeTimeDelay(){
  if (spinPerMinute == 0) {
    digitalWrite(enb, HIGH);
    delaySpeed = 0;
  }
  else {
    digitalWrite(enb, LOW);
    
    if (spinPerMinute > 0) digitalWrite(dir, HIGH);
    else digitalWrite(dir, LOW);
  }
}
