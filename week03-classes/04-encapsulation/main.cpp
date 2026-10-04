#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

class Player
{
public:
    explicit Player(std::string name)
        : name_(std::move(name)),
          health_(100)
    {
    }

    void takeDamage(int damage)
    {
        if (damage <= 0)
        {
            return;
        }

        health_ = std::max(0, health_ - damage);
    }

    void heal(int amount)
    {
        if (amount <= 0)
        {
            return;
        }

        health_ = std::min(100, health_ + amount);
    }

    [[nodiscard]]
    bool isAlive() const
    {
        return health_ > 0;
    }

    [[nodiscard]]
    int health() const
    {
        return health_;
    }

    [[nodiscard]]
    const std::string& name() const
    {
        return name_;
    }

private:
    std::string name_;
    int health_;
};

void printPlayer(const Player& player)
{
    std::cout << player.name()
              << " has "
              << player.health()
              << " HP\n";
}

int main()
{
    Player player{"Knight"};

    printPlayer(player);

    std::cout << "\nPlayer takes 30 damage\n";
    player.takeDamage(30);
    printPlayer(player);

    std::cout << "\nPlayer heals 20 HP\n";
    player.heal(20);
    printPlayer(player);

    std::cout << "\nPlayer takes 200 damage\n";
    player.takeDamage(200);
    printPlayer(player);

    if (!player.isAlive())
    {
        std::cout << player.name()
                  << " has been defeated\n";
    }

    return 0;
}