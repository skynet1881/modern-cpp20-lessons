#include <array>
#include <iostream>

int main()
{
    constexpr int low_stock_threshold = 3;

    const std::array<int, 6> stock_levels{
        12,
        3,
        0,
        8,
        2,
        15
    };

    std::cout << "=== Warehouse Stock Check ===\n\n";

    int product_id = 1;

    for (const auto stock : stock_levels)
    {
        std::cout << "Product "
                  << product_id
                  << ": ";

        if (stock == 0)
        {
            std::cout << "OUT OF STOCK";
        }
        else if (stock <= low_stock_threshold)
        {
            std::cout << "LOW STOCK";
        }
        else
        {
            std::cout << "OK";
        }

        std::cout << " (" << stock << " units)\n";

        ++product_id;
    }

    std::cout << "\nChoose action:\n";
    std::cout << "1 - Create reorder report\n";
    std::cout << "2 - Show inventory\n";
    std::cout << "3 - Exit\n";

    int action = 0;

    std::cin >> action;

    switch (action)
    {
        case 1:
            std::cout << "Creating reorder report...\n";
            break;

        case 2:
            std::cout << "Displaying inventory...\n";
            break;

        case 3:
            std::cout << "Goodbye.\n";
            break;

        default:
            std::cout << "Unknown command.\n";
            break;
    }

    return 0;
}