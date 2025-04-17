
 // Define pin connections
 const int photoSensorPin = A1;   // Photosensor connected to analog pin A0
 const int tempSensorPin = A0;    // TMP36 connected to analog pin A1

int lightValue;
float tempC;


//how to keep fan on for a given period but allow everytyhing else to keep working in background.

 
void setup() {
 
   // Initialize serial communication
   Serial.begin(9600);

  // Button interrupt setup
  attachInterrupt(0, tempSensorOverride, FALLING);
  attachInterrupt(1, lightSensorOverride, FALLING);
}
 
void loop() {
   
  // Read photosensor value (0-1023)
  lightValue = analogRead(photoSensorPin);
   
  // Read TMP36 temperature sensor
  int tempValue = analogRead(tempSensorPin);
   
  // Convert TMP36 reading to voltage (0-5V range)
  float voltage = tempValue * (5.0 / 1024.0);
   
  // Convert voltage to temperature in Celsius (TMP36 has 10mV/°C scale with 500mV offset)
  tempC = (voltage - 0.5) * 100;
  Serial.write(tempC);
  delay(1000);
   
  // Convert Celsius to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  checkLight();
  delay(2000);
  checkTemp();
  
  // Wait for a second before next reading
  delay(1000);
}

void checkLight(){
  if (lightValue < 10){
    Serial.write("L");
  }
  else{
    Serial.write("D");
  }
}

void checkTemp(){
  if (tempC > 23.0){
    Serial.write("C");
  }
  else{
    Serial.write("H");
  }
}

void tempSensorOverride(){
  
  static unsigned long lastDebounceTime = 0;

  if (millis() - lastDebounceTime > 200) { // 200ms debounce time
    Serial.write("C");
  }
  lastDebounceTime = millis();
}

void lightSensorOverride(){
  static unsigned long lastDebounceTime = 0;

  if (millis() - lastDebounceTime > 200) { // 200ms debounce time
    Serial.write("L");
 
  }
  lastDebounceTime = millis();
}
