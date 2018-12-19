void setupLogick(){}

void updateLogick(){
  makeSpeed();
  makeTimeDelay();
}

void makeSpeed(){
  switch (positionOfEncoder / 2){
    case 0 : { spinPerMinute = 4; delaySpinTime = 200; } break;
    case 1 : { spinPerMinute = 2; delaySpinTime = 320; } break;
    case 2 : { spinPerMinute = 1.3; delaySpinTime = 600; } break;
    case 3 : { spinPerMinute = 1; delaySpinTime = 900; } break;
    
    case 4 : { spinPerMinute = 0.8; delaySpinTime = 1200; } break;
    case 5 : { spinPerMinute = 0.66; delaySpinTime = 1400; } break;
    case 6 : { spinPerMinute = 0.5; delaySpinTime = 1800; } break;
    case 7 : { spinPerMinute = 0.4; delaySpinTime = 2400; } break;
    
    case 8 : { spinPerMinute = 0.33; delaySpinTime = 2800; } break;
    case 9 : { spinPerMinute = 0.25; delaySpinTime = 4000; } break;
    case 10: { spinPerMinute = 0.16; delaySpinTime = 6000; } break;
    case 11: { spinPerMinute = 0.12; delaySpinTime = 8000; } break;

    default : { spinPerMinute = 2; delaySpinTime = 300; } break;
  }
}

void makeTimeDelay() {
  if (spinPerMinute > 0) digitalWrite(dir, HIGH);
  else digitalWrite(dir, LOW);
}
