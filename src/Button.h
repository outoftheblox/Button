#ifndef _Button_H
#define _Button_H

#include <functional>

namespace ootb
{

    class Button
    {
        private:
            uint8_t pin;
            bool pullup;

            unsigned int debounceDelay = 200; //millis
            unsigned long lastChange; //millis

            bool state;
            std::function<void(void)> onChangeHandler;

        public:
            Button(uint8_t pin, bool pullup = false, unsigned int debounceDelay = 200);
            ~Button();

            void onChange(std::function<void()> function);

            bool pressed();

            void begin();
            void handle();

        private:
            void isr();
    };
}

#endif
