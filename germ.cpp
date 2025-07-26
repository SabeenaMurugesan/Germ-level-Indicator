int sensorPin = A0;
int sensorValue;

int redLED = 8;
int yellowLED = 9;
int greenLED = 10;

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Sensor Reading: ");
  Serial.println(sensorValue);

  if (sensorValue > 600) {
    // Very dirty / lots of gas detected
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
  } 
  else if (sensorValue > 400) {
    // Medium contamination
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);
  } 
  else {
    // Clean
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(1000); // 1-second delay
}
