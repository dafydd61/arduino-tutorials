/*
 * doubleBlink.ino
 * (You can't do this with delay)
 * https://www.tinkercad.com/things/eAfuCWjDizA
 * 
 * Blink 2 LEDs at arbitrary rates.
 * Now we can have several things happening on their own schedules,
 * which would have been either a pain or impossible with delay()
 * 
 * Hey! You should do this with arrays, so you don't duplicate all that code!
*/

int ledPin1 = 9;
long interval1 = 1000;
unsigned long lastChange1 = 0;
int ledState1 = LOW;

int ledPin2 = 10;
long interval2 = 813; // slightly faster than LED1
unsigned long lastChange2 = 0;
int ledState2 = LOW;


void setup()
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop()
{ 
  unsigned long now = millis();
  
  // Do LED1:
  int elapsed1 = now - lastChange1;
  if (elapsed1 >= interval1) {
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
    digitalWrite(ledPin1, ledState1);
    lastChange1 = now;
  }

  // Do LED2:
  int elapsed2 = now - lastChange2;
  if (elapsed2 >= interval2) {
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
    digitalWrite(ledPin2, ledState1);
    lastChange2 = now;
  }
}
