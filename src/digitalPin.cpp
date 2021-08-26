#include "digitalPin.h"


// Constructor
digitalPin::digitalPin(uint8_t pinNumber,
                       uint8_t Mode)
    : _pinNumber(pinNumber),
      _isOutput(false)
{
    // Update the output pin flag.
    if (Mode == OUTPUT)
        _isOutput = true;

    // Configure the pin.
    pinMode(pinNumber, Mode);
}                       


// For Output digitalPins:

// Set the pin state to high or low.
void digitalPin::setState(uint8_t pinState)
{
    if (_isOutput)
        digitalWrite(_pinNumber, pinState);
}


// Toggle the current pin state.
void digitalPin::toggleState()
{
    if (_isOutput)
        digitalWrite(_pinNumber, !digitalRead(_pinNumber));
}


// For Input and Output Pins.

// Read the pin state.
uint8_t digitalPin::getState()
{
    return digitalRead(_pinNumber);
}
