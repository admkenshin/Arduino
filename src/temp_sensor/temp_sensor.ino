//> Constants ---------------------------------------<
const int sensorPin = A0;
const float baselineTemp = 20.0;
const float ADC_RANGE = 1024.0;

void setup() {
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Calculate the voltage
  float voltage = (sensorVal/ADC_RANGE) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // Convert to Celsius
  Serial.print(" V, Temperature: ");
  int temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);
  Serial.print("\n");

  // Light indiator LEDs
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temperature >= baselineTemp + 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  //else if (temperature >= baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  //}

  delay(1000);
}
