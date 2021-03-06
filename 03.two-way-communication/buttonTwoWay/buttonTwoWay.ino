int inputPin = 2;
int outputPin = 5;

void setup() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int value = Serial.parseInt();
    analogWrite(outputPin, value);
  }

  int buttonState = map(digitalRead(inputPin), 0, 1, 0, 255);
  Serial.println(buttonState);
}
