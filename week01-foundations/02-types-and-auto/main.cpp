#include <iostream>
#include <string>

int main()
{
    std::string destination = "Berlin";

    int number_of_packages = 3;
    double weight_per_package_kg = 2.4;
    bool priority_shipping = true;

    auto total_weight_kg = number_of_packages * weight_per_package_kg;
    auto price_per_kg = 1.75;
    
    auto shipping_cost = total_weight_kg * price_per_kg;

    if (priority_shipping)
    {
        shipping_cost += 5.0;
    }

    std::cout << "Destination: "
              << destination
              << '\n';

    std::cout << "Packages: "
              << number_of_packages
              << '\n';
              
    std::cout << "Total weight: "
              << total_weight_kg
              << '\n';

    std::cout << "Priority shipping: "
              << priority_shipping
              << '\n';

    std::cout << "Shipping cost: Euro "
              << shipping_cost
              << '\n';

    return 0;
}