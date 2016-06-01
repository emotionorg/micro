// WWW.BUILDCIRCUIT.COM//

#include <Wtv020sd16p.h>
//RESET = PIN 2
//CLOCK = PIN 3
//DATA = PIN 4
//BUSY = PIN 5

int resetPin = 2; // The pin number of the reset pin.
int clockPin = 3; // The pin number of the clock pin.
int dataPin = 4; // The pin number of the data pin.
int busyPin = 5; // The pin number of the busy pin.

Wtv020sd16p wtv020sd16p(resetPin,clockPin,dataPin,busyPin);

void setup() 
{
//Initializes the module.
wtv020sd16p.reset();
// initialize the SELECTOR and Trigger button pins as a inputs:
Serial.begin(9600);
}
void loop() 
{
  while (Serial.available() > 0) // Don't read unless
  {
    unsigned long number = Serial.parseInt();
    say(number);
    wtv020sd16p.reset();
  }
         
}


