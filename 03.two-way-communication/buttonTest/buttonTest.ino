int inputPin = 2;
int outputPin = 5;
int lastReading = HIGH;

void setup() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(inputPin);
  if (buttonState == LOW && lastReading == HIGH) {
    int newValue = random(256);
    analogWrite(outputPin, newValue);
    delay(30);
  }
  lastReading = buttonState;
  delay(30);
}
