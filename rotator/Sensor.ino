void setupSensor(){
  pinMode(sensorPin, INPUT);
}

void updateSensor(){
  if (digitalRead(sensorPin) != lastStateOfSensorPin){
    lastStateOfSensorPin = digitalRead(sensorPin);
    spins++;
  }
}
