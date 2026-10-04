#include <iostream>
#include <string>
#include <vector>

struct Player
{
    std::string name;
    int health = 100;
    int score = 0;
};

void print_player(const Player& player)
{
    std::cout
        << player.name
        << " | health: "
        << player.health
        << " | score: "
        << player.score
        << '\n';
}

void add_score(Player& player, int amount)
{
    player.score += amount;
}

void take_damage(Player& player, int damage)
{
    player.health -= damage;

    if (player.health < 0)
    {
        player.health = 0;
    }
}

void simulate_damage(Player player, int damage)
{
    player.health -= damage;

    std::cout
        << "Simulation: "
        << player.name
        << " would have "
        << player.health
        << " health\n";
}

Player* find_player(std::vector<Player>& players, const std::string& name)
{
    for (Player& player : players)
    {
        if (player.name == name)
            return &player;
    }

    return nullptr;
}

const Player* find_player(const std::vector<Player>& players, const std::string& name)
{
    for (const Player& player : players)
    {
        if (player.name == name)
        {
            return &player;
        }
    }

    return nullptr;
}

int main()
{
    std::vector<Player> players{
        {
            .name = "Alice",
            .health = 100,
            .score = 10
        },
        {
            .name = "Bob",
            .health = 80,
            .score = 25
        },
        {
            .name = "Charlie",
            .health = 60,
            .score = 40
        }
    };

    std::cout << "Initial player \n";
    for (const Player& player : players)
    {
        print_player(player);
    }

    std::cout << "\n Search for Alice.. \n";
    Player *alice = find_player(players, "Alice");

    if (alice != nullptr)
    {
        add_score(*alice, 20);
        take_damage(*alice, 30);

        std::cout << "Alice update \n";
        print_player(*alice);
    }

    return 0;
}