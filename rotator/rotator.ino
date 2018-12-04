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

long millisecondCommon;
int millisecondLast;
int millisecond;
int second;
int minute;
int hour;
int lastSendSecond;

double spinPerMinute = 1;
double delaySpeed = 1200;

int spinSparps = 60;
bool lastStateOfSensorPin = false;
int spins = 0;
double numberOfSpinning = 0;
bool spinSide = false;

bool lastPush = false;
bool isWork = true;

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
