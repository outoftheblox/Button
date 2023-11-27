#include <Arduino.h>
#include "Button.h"

using namespace ootb;

Button::Button(uint8_t pin, bool pullup, unsigned int debounceDelay)
:
    pin(pin),
    pullup(pullup),
    debounceDelay(debounceDelay)
{
}

Button::~Button()
{
}

void Button::onChange(std::function<void()> function)
{
    onChangeHandler = function;
}

void Button::begin()
{
    pinMode(pin, pullup ? INPUT_PULLUP : INPUT);
    lastChange = millis() - debounceDelay;
}

void Button::handle()
{
    bool currentState = pullup ? !digitalRead(pin) : digitalRead(pin);
    unsigned long now = millis();
    if (state != currentState && now - lastChange > debounceDelay)
    {
        lastChange = millis();
        state = currentState; 
        if (!onChangeHandler) return;
        onChangeHandler();
    }
}

bool Button::pressed()
{
    return state;
}
