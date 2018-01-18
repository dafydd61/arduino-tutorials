/*
 * automaticDoor.ino
 * https://www.tinkercad.com/things/cJi2remP4yp
 * 
 * Not really automatic, in this case. More pushbutton.
 * A practical application of non-blocking code.
 *
 * When sombody presses the button, hold the door open for 5 seconds.
 * If somebody else presses the button while the door is open,
 * extend the open time, so it doesn't close in their face as they walk through.
 */

#include <Servo.h>

int buttonPin = 4;
int servoPin = 9;

int lastButtonState = HIGH;

long interval = 5000;
unsigned long triggerTime = 0;
int doorState = 0; // 0 = closed; 90 = open

Servo doorServo;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  doorServo.attach(servoPin);
  
  doorServo.write(doorState);
}

void loop()
{
  // Has somebody pressed the button?
  int buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay (30); // debounce
    triggerTime = millis();
    if (doorState == 0) {
      doorState = 90;
      doorServo.write(doorState);
    }
  }  
  lastButtonState = buttonState;
  
  //Has the door been open for 5 seconds?
  
  unsigned long now = millis();
  int elapsed = now - triggerTime;
  if (elapsed >= interval && doorState == 90) {
    doorState = 0;
    doorServo.write(doorState);
  }
  
  delay(30);
}
