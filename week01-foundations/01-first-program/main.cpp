#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Modern C++20 ===\n";

    std::cout << "What is your name? ";

    std::string name;
    std::cin >> name;

    std::cout << "Hello, " << name << "!\n";
    std::cout << "Your C++ environment is working.\n";

    return 0;
}