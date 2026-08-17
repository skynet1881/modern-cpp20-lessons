#include <array>
#include <iomanip>
#include <iostream>

int main()
{
    constexpr double vat_rate = 0.19;

    constexpr int max_retry_count = 3;

    constexpr std::array<int, max_retry_count> retry_delays{
        1,
        2,
        4
    };

    std::cout << "Enter net price: ";

    double net_price = 0.0;
    std::cin >> net_price;

    const double vat =
        net_price * vat_rate;

    const double total_price =
        net_price + vat;

    std::cout << std::fixed
              << std::setprecision(2);

    std::cout << "Net:   €"
              << net_price
              << '\n';

    std::cout << "VAT:   €"
              << vat
              << '\n';

    std::cout << "Total: €"
              << total_price
              << '\n';

    std::cout << "\nRetry delays: ";

    for (const auto delay : retry_delays)
    {
        std::cout << delay << "s ";
    }

    std::cout << '\n';

    return 0;
}