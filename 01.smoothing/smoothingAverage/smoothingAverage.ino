/*
 * smoothingAverage
 * 
 * Smooth a signal by avearging the last n samples
 * 
 * Useful for slowing down transitions and reducing noise
 */
 
// larger sample set -> slower transition/more resilience
#define READINGS_LENGTH 20

int readings[READINGS_LENGTH];
int index = 0;

int inputPin = 0;
int outputPin = 9;

void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(inputPin) / 4;
  readings[index] = reading;
  
  float total = 0;
  for (int i = 0; i < READINGS_LENGTH; i++) {
    total += readings[i];
  }  
  float outputValue = total / READINGS_LENGTH;

  analogWrite(outputPin, outputValue);
  
  Serial.print(reading);
  Serial.print(" ");
  Serial.println(outputValue);

  index = (index + 1) % READINGS_LENGTH;

  delay(30);
}
