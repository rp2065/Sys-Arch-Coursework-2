// Button Test Code with Debouncing
const int buttonPin1 = 2;  // First button on digital pin 2
const int buttonPin2 = 3;  // Second button on digital pin 3

// Debounce variables
unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
const int debounceDelay = 50;  // milliseconds

// Current stable states
int buttonState1 = HIGH;
int buttonState2 = HIGH;
int lastButtonState1 = HIGH;
int lastButtonState2 = HIGH;

void setup() {
  Serial.begin(9600);
  
  // Initialize buttons with internal pull-up resistors
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  Serial.println("Button Test Started");
  Serial.println("------------------");
  Serial.println("Press either button...");
  Serial.println();
}

void loop() {
  // Read current button states
  int currentState1 = digitalRead(buttonPin1);
  int currentState2 = digitalRead(buttonPin2);
  
  // ===== Button 1 Handling =====
  if (currentState1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }
  
  if ((millis() - lastDebounceTime1) > debounceDelay) {
    if (currentState1 != buttonState1) {
      buttonState1 = currentState1;
      
      if (buttonState1 == LOW) {
        Serial.println("Button 1 (Pin 2) pressed!");
      } else {
        Serial.println("Button 1 (Pin 2) released");
      }
    }
  }
  
  // ===== Button 2 Handling =====
  if (currentState2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }
  
  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (currentState2 != buttonState2) {
      buttonState2 = currentState2;
      
      if (buttonState2 == LOW) {
        Serial.println("Button 2 (Pin 3) pressed!");
      } else {
        Serial.println("Button 2 (Pin 3) released");
      }
    }
  }
  
  // Save current states for next loop
  lastButtonState1 = currentState1;
  lastButtonState2 = currentState2;
  
  // Small delay to prevent Serial Monitor spam
  delay(10);
}
