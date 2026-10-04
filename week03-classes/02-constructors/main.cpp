#include <iostream>
#include <string>
#include <utility>

class User
{
public:
    // Default constructor
    User()
        : name_("Guest"),
          age_(0)
    {
        std::cout << "Default constructor called\n";
    }

    // Constructor with parameters
    User(std::string name, int age)
        : name_(std::move(name)),
          age_(age)
    {
        std::cout << "Parameterized constructor called\n";
    }

    void print() const
    {
        std::cout << "Name: " << name_
                  << ", age: " << age_
                  << '\n';
    }

private:
    std::string name_;
    int age_;
};

int main()
{
    std::cout << "Creating first user:\n";

    User guest;
    guest.print();

    std::cout << "\nCreating second user:\n";

    User alice{"Alice", 30};
    alice.print();

    return 0;
}