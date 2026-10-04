#include <iostream>
#include <string>

double calculate_total(double price, int quantity)
{
    return price * quantity;
}

double calculate_total(double price, int quantity, double discount)
{
    return (price - discount) * quantity;
}

void print_order(const std::string& name, double total)
{
    std::cout << name << ": $" << total << "\n";
}

int main() 
{
    const double keyboard_total = calculate_total(79.5, 4);

    const double mouse_total = calculate_total(20, 2);

    const double usb_camera = calculate_total(25, 2, 5);

    print_order("Keyboard", keyboard_total);
    print_order("Mouse", mouse_total);
    print_order("Usb camera", usb_camera);

    return 0;
}