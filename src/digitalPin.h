#ifndef DIGITALPIN_H
#define DIGITALPIN_H

#include "Arduino.h"
#include <stdint.h>

/* 
 * A library to implement a digitalPin class for the Arduino IDE.
 * This class is designed only for the IDE, but can be used unchanged
 * by PlatformIO provided that the project using it, is using the 
 * Arduino Framework and has this defined in the platformio.ini file.
 * 
 * Norman Dunbar
 * 26 August 2021.
 */

class digitalPin {

public:
     // Constructor.
    digitalPin(uint8_t pinNumber,
               uint8_t Mode);

    // There is no destructor as a digitalPin should never go out of scope.
    // Famous last words?


    // For Output digitalPins:
    void setState(uint8_t pinState);
    void toggleState();

    // For Input and Output Pins
    uint8_t getState();

private:

    // The Arduino pin number. This is 0 through 13,
    // A0 through A5 which can be referenced as 14
    // through 19 too.
    uint8_t _pinNumber;

    // Flag to indicate if this is an output pin.
    bool _isOutput;
};


#endif // DIGITALPIN_H