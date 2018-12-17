#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
//LiquidCrystal lcd(2,3,31,33,35,37);

#define enb 13
#define dir 12
#define pul 11
#define sensorPin 8
#define soundPin 9

#define rulerButtonPin 53
#define outputA 49
#define outputB 51

int timerCounter = 0;

int counter = 20; 
int aState;
int aLastState;

unsigned long sendPer1Seconds = 20;
unsigned long microsecondCommon;
unsigned long microsecondCommonForEngine;
unsigned long microsecondMax = 1000000ul;
unsigned long thousand = 1000ul;
unsigned long millisecondLastPushButton;
unsigned long millisecondCommon;
unsigned long millisecondLastForEngine;
unsigned long millisecondLast;
int millisecond;
int second;
int minute;
int hour;
int lastSendSecond;
int lastSendMicrosecond;
int lastEngineSpinTime = 0;


unsigned long lastTimeOfChanging = 0;
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

int signalTimeMax = 32;
int signalTime = signalTimeMax;
bool isPushedButton = false;
bool isWork = true;

void setup() {
  setupTimer();
  setupSensor();
  setupRuler();
  setupMonitor();
  setupEngine();
  setupSound();
}

void loop() {
  updateTimer();
  updateRuler();
  updateSensor();
  updateLogick();
  updateEngine();
  updateMonitor();
  updateSound();
}
