#ifndef _Button_H
#define _Button_H

#include <functional>

namespace ootb
{

    class Button
    {
        private:
            unsigned int pin;

            unsigned int debounceDelay = 200; //millis

            bool clicked;
            unsigned long nextClick; //millis
            std::function<void(void)> onClickHandler;

        public:
            Button(unsigned int pin);
            ~Button();

            void onClick(std::function<void()> function);

            void begin();
            void handle();

        private:
            void isr();
    };
}

#endif
