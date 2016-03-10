//> Includes ------------------------------------------------------------------<
#include <Arduino.h>

//> Constants -----------------------------------------------------------------<
const int sensorPin = A0;
const float baselineTemp = 20.0;
const float ADC_RANGE = 1024.0;


//> Global variables ----------------------------------------------------------<
float *listPtr;
float tempList[5] = {0};

//> Function declarations -----------------------------------------------------<
float temp_5sec_average(float temp);
template <typename T> T arrayAverage(T[], int length);

//> Function definitions ------------------------------------------------------<
void setup() {
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  // Set up running average pointer
  listPtr = tempList;
}

// main loop
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

  // Temperature should be some average
  float temperature = (voltage - 0.5) * 100;
  Serial.print(temp_5sec_average(temperature));
  Serial.print("\n");

  delay(1000);
}

// Returns a value that is the average of the last five values
float temp_5sec_average(float temp) {
  *listPtr = temp;

  // Update the pointer to the next position in the array
  if (listPtr == &tempList[5]) {
    listPtr = tempList;
  }
  else {
    listPtr += sizeof(float);
  }

  return arrayAverage(tempList, 5);
}

// Returns the average of an array
template <typename T> T arrayAverage(T *array, int length) {
  T sum = 0;
  for (int i = 0; i < length; i++) {
    sum += array[i];
  }

  return sum / length;
}
