
#include <LiquidCrystal.h>

int LEDS = 7; 
int motorPin = 6;
int incoming;


//Need to decide how to decipher the signal coming in and what it means
//Also add functionality to lcd in a designated function
//Function to turn fan/lights on
//Function to turn fan/lights off?

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  // Initialize serial communication
  Serial.begin(9600);

  pinMode(LEDS, OUTPUT);
  pinMode(motorPin, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  
}

void loop() {
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  //digitalWrite(LEDS, HIGH);
  //digitalWrite(motorPin, HIGH);

  if (Serial.available() > 0) {
    incoming = Serial.read();
    if (incoming == 'C'){
      fanOn();
    }
    if (incoming == 'L'){
      lightsOn();
    }
    if (incoming == 'D'){
      lightsOff();
    }
    if (incoming == 'H'){
      fanOff();
    }
  }
}

void fanOn(){
  digitalWrite(motorPin, HIGH);
}

void fanOff(){
  digitalWrite(motorPin, LOW);
}

void lightsOn(){
  digitalWrite(LEDS, HIGH);
}

void lightsOff(){
  digitalWrite(LEDS, LOW);
}
