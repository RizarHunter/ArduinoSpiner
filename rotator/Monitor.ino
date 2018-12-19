#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

unsigned long sendPer1Seconds = 2; // How many times send data per second to monitor
int lastSendMicrosecond; // field for time data of last sending
unsigned long oneSecondInMicros = 1000000ul; 

void setupMonitor() {
  lcd.begin(20, 2);
}

void updateMonitor() {
  updateDisplay();
}

void updateDisplay() {
  if (sendTimerDataToMonitor()) {
    if (isWork) printWork();
    else printPause();
    
    printAlways();
  }
}
void printWork(){
  lcd.setCursor(4, 0);
  lcd.print("WORK ");

}
void printPause(){
  if (millisecondCommon % 1000 > 500){
        lcd.setCursor(4, 0);
        lcd.print("PAUSE");
      }
      else{
        lcd.setCursor(4, 0);
        lcd.print("     ");
      }
}
void printAlways(){
  lcd.setCursor(0, 1);
  lcd.print(" " + String(spinPerMinute)+"  ");
  lcd.setCursor(8, 1);
  lcd.print(" sp/min ");
}

bool sendTimerDataToMonitor() {
  int numberOfPart = microsecondCommon / (oneSecondInMicros / sendPer1Seconds);
  if (numberOfPart != lastSendMicrosecond) {
      lastSendMicrosecond = numberOfPart;
      return true;
  }
  return false;
}
