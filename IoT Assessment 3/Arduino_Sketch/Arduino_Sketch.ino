int tempSensorValue;
int tempSensorPin = 1;

int ldrSensorValue = 0;
int ldrSensorPin = 0;

int tempLed = 13;
int ldrLed = 12;

char tempString[5];
String ldrString;

void setup() {
  pinMode(tempLed, OUTPUT);
  pinMode(ldrLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Obtain value from lm35 and calculate it into temperature
  tempSensorValue = analogRead(tempSensorPin);
  float mv = (tempSensorValue/1024.0) * 5000;
  float cel = mv/10;

  // Obtain value from LDR
  ldrSensorValue = analogRead(ldrSensorPin);
  
  // Send values to Pi
  dtostrf(cel, 2, 2, tempString);
  String data = tempString;
  data += "-";
  ldrString = String(ldrSensorValue);
  data += ldrString;
  Serial.println(data);

  if (cel > 30){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  if (ldrSensorValue > 200){
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  
  delay(5000);
}
