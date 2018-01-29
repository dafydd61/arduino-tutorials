int inputPin = 2;
int outputPin = 5;
byte value = 0;

void setup() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    value = Serial.parseInt();
    analogWrite(outputPin, value);
  }
}
