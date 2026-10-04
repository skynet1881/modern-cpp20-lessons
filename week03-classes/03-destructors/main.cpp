#include <iostream>
#include <string>
#include <utility>

class Connection
{
public:
    explicit Connection(std::string name)
        : name_(std::move(name))
    {
        std::cout << "Opening connection: "
                  << name_ << '\n';
    }

    ~Connection()
    {
        std::cout << "Closing connection: "
                  << name_ << '\n';
    }

    void send(std::string_view message) const
    {
        std::cout << name_
                  << " sending: "
                  << message
                  << '\n';
    }

private:
    std::string name_;
};

void communicate()
{
    std::cout << "Entering communicate()\n";

    Connection connection{"Server"};

    connection.send("Hello");

    std::cout << "Leaving communicate()\n";
}

int main()
{
    std::cout << "Program started\n\n";

    communicate();

    std::cout << "\nBack inside main()\n";

    {
        std::cout << "\nEntering nested scope\n";

        Connection database{"Database"};

        database.send("SELECT * FROM users");

        std::cout << "Leaving nested scope\n";
    }

    std::cout << "\nProgram finished\n";

    return 0;
}