#include "Button.h"
#include "Led.h"

#define BUTTON_PIN D3
#define LED_PIN BUILTIN_LED

using namespace ootb;

Button button(BUTTON_PIN, false, 1000);
Led led(LED_PIN);


void setup()
{
    Serial.begin(230400);
    Serial.println();

    led.off();
    button.begin();
    button.onChange([](){
        led.set(button.pressed());
        Serial.println(button.pressed());
    });
}

void loop()
{
    button.handle();
}
