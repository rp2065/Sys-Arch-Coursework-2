
#include <LiquidCrystal.h>

int LEDS = 7; 
int motorPin = 6;
int incoming;
bool fanOn = false;
bool lightOn = false;
unsigned long fanStart = 0;
unsigned long lightStart = 0;
unsigned long fanDuration = 100000;
unsigned long lightDuration = 100000;


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  // Initialize serial communication
  Serial.begin(9600);

  pinMode(LEDS, OUTPUT);
  pinMode(motorPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Fan: OFF");
  lcd.setCursor(1,0);
  lcd.print("Temp: ");
}

void loop() {

  unsigned long currentTime = millis();

  if (Serial.available() > 0) {
    incoming = Serial.read();
    if (incoming == 'C'){
      fanOn();
    }
    else if (incoming == 'L'){
      lightsOn();
    }
    else if (incoming == 'D'){
      lightsOff();
    }
    else if (incoming == 'H'){
      fanOff();
    }
    else{
      lcd.setCursor(6, 1);
      lcd.print(incoming);
    }
  }
  if (fanOn && (currentTime - fanStart >= fanDuration)){
    fanOff();
  }
  if (lightOn && (currentTime - lightStart >= lightDuration)){
    lightsOff();
  }
}

void fanOn(){
  lcd.setCursor(5,0);
  lcd.print("ON");
  digitalWrite(motorPin, HIGH);
  fanStart = millis();
  fanOn = true;
}

void fanOff(){
  lcd.setCursor(5,0);
  lcd.print("OFF");
  digitalWrite(motorPin, LOW);
  fanOn = false;
}

void lightsOn(){
  digitalWrite(LEDS, HIGH);
  lightStart = millis();
  lightOn = true;
}

void lightsOff(){
  digitalWrite(LEDS, LOW);
  lightOn = false;
}
