// Example code for testing that sensors work

// Define pin connections
const int photoSensorPin = A1;   // Photosensor connected to analog pin A0
const int tempSensorPin = A0;    // TMP36 connected to analog pin A1

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Print header
  Serial.println("Light Level\tTemperature (C)\tTemperature (F)");
  Serial.println("----------------------------------------------");
}

void loop() {
  // Read photosensor value (0-1023)
  int lightValue = analogRead(photoSensorPin);
  
  // Read TMP36 temperature sensor
  int tempValue = analogRead(tempSensorPin);
  
  // Convert TMP36 reading to voltage (0-5V range)
  float voltage = tempValue * (5.0 / 1024.0);
  
  // Convert voltage to temperature in Celsius (TMP36 has 10mV/°C scale with 500mV offset)
  float tempC = (voltage - 0.5) * 100;
  
  // Convert Celsius to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  
  // Print all values to serial monitor
  Serial.print(lightValue);
  Serial.print("\t\t");
  Serial.print(tempC);
  Serial.print(" C\t\t");
  Serial.print(tempF);
  Serial.println(" F");
  
  // Wait for a second before next reading
  delay(1000);
}
