void setupSensor(){
  pinMode(sensorPin, INPUT);
}

void updateSensor(){
  if (digitalRead(sensorPin) != lastStateOfSensorPin 
   //&& digitalRead(sensorPin) != true
   ){
    lastStateOfSensorPin = digitalRead(sensorPin);
    spins++;
  }
}
