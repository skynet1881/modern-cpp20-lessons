#include <iostream>
#include "led.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    LED led(13); // Create an LED object on pin 13

    return 0;
}