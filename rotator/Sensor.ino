#define sensorPin 31

void setupSensor() {
  pinMode(sensorPin, INPUT);
}

void updateSensor() {
  positionOfSensor = digitalRead(sensorPin);
}
