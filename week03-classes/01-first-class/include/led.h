#pragma once

class LED
{
    public:
        LED(int pin);
        void on();
        void off();
        void toggle();
        bool isOn() const;
    
    private:
        int pin;
};