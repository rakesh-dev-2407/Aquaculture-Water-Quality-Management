#define TdsSensorPin A0   // Connect the TDS sensor to A0 pin
float voltage, tdsValue, temperature = 25; // Assuming the temperature is 25°C

void setup() {
  Serial.begin(9600);
  pinMode(TdsSensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(TdsSensorPin);  // Read analog value from the sensor
  voltage = sensorValue * (3.3 / 1024.0);  // Convert the analog value to voltage (for 3.3V system)
  
  // Calculate the TDS value from voltage, with a simple calibration factor (you can adjust it)
  tdsValue = (133.42 * voltage * voltage * voltage - 255.86 * voltage * voltage + 857.39 * voltage) * 0.5;

  Serial.print("Analog Value: "); Serial.println(sensorValue);
  Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
  Serial.print("TDS Value: "); Serial.print(tdsValue); Serial.println(" ppm");

  delay(1000);  // Delay 1 second
}
