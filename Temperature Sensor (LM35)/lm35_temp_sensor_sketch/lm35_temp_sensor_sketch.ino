int sensorValue;
int sensorPin = 1;

void setup() {
    Serial.begin(9600);
}

void loop() {
  // Obtain raw value from sensor (Not Celcius)
  sensorValue = analogRead(sensorPin);

  // Converting into Celcius
  float mv = (sensorValue/1024.0) * 5000;
  float cel = mv/10;
  Serial.print("Temperature: ");
  Serial.println(cel);
  delay(1000);
}
