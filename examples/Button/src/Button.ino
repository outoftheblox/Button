#include <Button.h>
#include <Led.h>
#include <functional>

#define BUTTON_PIN D3
#define LED_PIN BUILTIN_LED

using namespace ootb;

Button button(BUTTON_PIN);
Led led(LED_PIN, true);

bool on = false;

void setup()
{
    Serial.begin(230400);
    Serial.println();

    button.begin();
    button.onClick([](){
        on = !on;
        led.set(on);
        Serial.println("Clicked");
    });
}

void loop()
{
    button.handle();
}
