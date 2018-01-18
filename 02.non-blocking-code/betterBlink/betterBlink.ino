/*
 * betterBlink.ino
 * https://www.tinkercad.com/things/h9r1RBD2sAc
 * 
 * Blink witout using delay.
 * The Arduino doesn't come to a stop between switches, meaning other stuff can happen!
 * 
 * The basics:
 * - Remember the last time you switched the LED (lastChange)
 * - Every cycle, check to see if a second (interval) has passed since you last switched
 * - If so, switch, and make a note by updating lastChange
 */

int ledPin1 = 9;
long interval = 1000;
unsigned long lastChange = 0;
int ledState = LOW;

void setup()
{
  pinMode(ledPin1, OUTPUT);
}

void loop()
{
  /* We're going to avoid doing this:
  digitalWrite(ledPin1, HIGH);
  delay(interval);
  digitalWrite(ledPin1, LOW);
  delay(interval);
  */
  
  
  // This is more complicated, but way better:
  unsigned long now = millis();
  int elapsed = now - lastChange;
  
  if (elapsed >= interval) {
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin1, ledState);
    lastChange = now;
  }
}
