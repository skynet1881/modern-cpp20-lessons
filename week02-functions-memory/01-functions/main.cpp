#include <iostream>
#include <string>

double calculate_total(double price, int quantity)
{
    return price * quantity;
}

double calculate_total(double price, int quantity, double discount)
{
    const double total = price * quantity;
    return total * (1.0 - discount);
}

void print_order(const std::string& product, double total)
{
    std::cout << product << ": $" << total << '\n';
}

int main()
{
    const double keyboard_total =
        calculate_total(79.99, 2);

    const double mouse_total =
        calculate_total(49.99, 3, 0.10);

    print_order("Keyboard", keyboard_total);
    print_order("Mouse", mouse_total);

    return 0;
}