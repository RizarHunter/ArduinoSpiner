#define sensorPin 8

void setupSensor() {
  pinMode(sensorPin, INPUT);
}

void updateSensor() {
  positionOfSensor = digitalRead(sensorPin);
}
