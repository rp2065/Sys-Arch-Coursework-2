
#include <LiquidCrystal.h>

int statusLight;
int LEDS[]; 
int tempSensorButton;
int motionSensorButton;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup() {
  
  attachInterrupt(0, tempSensorOverride, FALLING);
  attachInterrupt(1, motionSensorOverride, FALLING);

  for (int i=0; i<5; i++){
    pinMode(LEDS[i], OUTPUT);
  }

  pinMode(statusLight, OUTPUT);
  pinMode(tempSensorButton, INPUT);
  pinMode(motionSensorButton, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // testing git functionality
}

void setFanSpeed(){
  
}

void setLightBrightness(){
  
}

void tempSensorOverride(){
  static unsigned long lastDebounceTime = 0;

  if (millis() - lastDebounceTime > 200) { // 200ms debounce time
    //do something during interrupt
  }
  lastDebounceTime = millis();
}

void motionSensorOverride(){
  static unsigned long lastDebounceTime = 0;

  if (millis() - lastDebounceTime > 200) { // 200ms debounce time
    //do something during interrupt
  }
  lastDebounceTime = millis();
}
