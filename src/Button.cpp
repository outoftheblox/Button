#include "Button.h"
#include "FunctionPointer.h"
#include <Arduino.h>

using namespace ootb;
using namespace std;

Button::Button(unsigned int pin)
:
    pin(pin)
{
}

Button::~Button()
{
}

void Button::onClick(std::function<void()> function)
{
    onClickHandler = function;
}

void Button::handle()
{
    if (!clicked) return;
    if (!onClickHandler)
    {
        Serial.println("No click handler");
        return;
    }
    onClickHandler();
    clicked = false;
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
    nextClick = millis();
    auto fn = FunctionPointer<void()>([&]
    {
        isr();
    });
    attachInterrupt(digitalPinToInterrupt(pin), fn, CHANGE);
}

void Button::isr()
{
    bool down = !digitalRead(pin);
    if (down && millis() > nextClick)
    {
        nextClick = millis() + debounceDelay;
        clicked = true;
    }
}
