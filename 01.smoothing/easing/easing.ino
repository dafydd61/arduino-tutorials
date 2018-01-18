/*
 * easing
 * 
 * Smooth a signal by moving partway to your target each cycle
 * 
 * Useful for slowing down transitions and reducing noise
 */
 
// Connect pin 2 to GND through the switch, and use a pull-up resistor to +5

int ledPin = 9;
int inputPin = 0;
int lastReading = 0; // remember what the last reading was
int targetValue = 0; // where are we going?
float currentValue = 0; //where are we right now? Use a float because we're going to be multiplying by fractions
float scale = .1;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  targetValue = analogRead(inputPin) / 4;
  
  // You probably want to do some map() and constrain() magic here...

  float diff = targetValue - currentValue; // How far are we from the target?
  currentValue = currentValue + (diff * scale); // move 1/10 of the distance

  analogWrite(ledPin, currentValue);
  Serial.print(targetValue);
  Serial.print(" ");
  Serial.println(currentValue);
    
  delay(30);
}
