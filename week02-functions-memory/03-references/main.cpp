#include <iostream>
#include <string>

struct Player
{
    std::string name;
    int health;
};

void take_damage(Player player, int damage)
{
    std::cout << "\nInside take_damage()\n";
    std::cout << "Address: " << &player << '\n';

    player.health -= damage;

    std::cout << player.name
              << " now has "
              << player.health
              << " health\n";
}

int main()
{
    Player player{
        .name = "Alice",
        .health = 100
    };

    std::cout << "Before function call\n";
    std::cout << "Address: " << &player << '\n';
    std::cout << "Health: " << player.health << '\n';

    take_damage(player, 25);

    std::cout << "\nAfter function call\n";
    std::cout << "Address: " << &player << '\n';
    std::cout << "Health: " << player.health << '\n';

    return 0;
}