bool isWork = true;

int positionOfEncoder = 2;
bool positionOfSensor = false;

unsigned long microsecondCommon; // microsecond from beginning of program (70m to restart)
unsigned long millisecondCommon; // millisecond from beginning of program (50d to restart)

double spinPerMinute = 1;
int delaySpinTime = 10000; // delay for spinning engine

void setup() {
  setupTimer();
  setupSensor();
  setupRuler();
  setupLogick();
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
