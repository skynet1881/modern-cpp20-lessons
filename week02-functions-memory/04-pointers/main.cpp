#include <iostream>
#include <string>

struct Player
{
    std::string name;
    int health;
};

void print_player(const Player* player)
{
    if (player == nullptr)
    {
        std::cout << "No player selected\n";
        return;
    }

    std::cout
        << "Name: " << player->name << '\n'
        << "Health: " << player->health << '\n';
}

void take_damage(Player* player, int damage)
{
    if (player == nullptr)
    {
        return;
    }

    player->health -= damage;

    if (player->health < 0)
    {
        player->health = 0;
    }
}

int main()
{
    Player alice{
        .name = "Alice",
        .health = 100
    };

    Player* selected_player = &alice;

    std::cout << "Object address:  "
              << &alice
              << '\n';

    std::cout << "Pointer value:   "
              << selected_player
              << '\n';

    std::cout << "\nSelected player\n";
    print_player(selected_player);

    take_damage(selected_player, 30);

    std::cout << "\nAfter damage\n";
    print_player(selected_player);

    selected_player = nullptr;

    std::cout << "\nAfter clearing selection\n";
    print_player(selected_player);

    return 0;
}