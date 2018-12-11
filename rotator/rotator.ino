#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1,4,5,6,7);


#define enb 13
#define dir 12
#define pul 11
#define sensorPin 7

#define rulerButtonPin 53
#define outputA 49
#define outputB 51

int counter = 20; 
int aState;
int aLastState;

unsigned long sendPer1Seconds = 20;
unsigned long microsecondCommon;
unsigned long microsecondMax = 1000000ul;
unsigned long thousand = 1000ul;
unsigned long millisecondCommon;
int millisecondLast;
int millisecond;
int second;
int minute;
int hour;
int lastSendSecond;
int lastSendMicrosecond;
int lastEngineSpinTime = 0;


unsigned long lastTimeOfChaging = 0;
double spinPerMinute = 1;
unsigned long delaySpeed = 10000;
double delayStop = 340;
unsigned long delayCounter = 0;
unsigned long delayCounterMillis = 0;
bool pulBool = false;

int spinSparps = 60;
bool lastStateOfSensorPin = false;
int spins = 0;
unsigned long numberOfSpinning = 0;
bool spinSide = false;

void setup() {
  setupTimer();
  setupSensor();
  setupRuler();
  setupMonitor();
  setupEngine();
}

void loop() {
  updateTimer();
  updateRuler();
  updateSensor();
  updateLogick();
  updateEngine();
  updateMonitor();
}
