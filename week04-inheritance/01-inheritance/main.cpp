#include <iostream>
#include <string>
#include <utility>

class Employee
{
public:
    explicit Employee(std::string name)
        : name_{std::move(name)}
    {
        std::cout << "Employee constructor: " << name_ << '\n';
    }

    void clockIn() const
    {
        std::cout << name_ << " clocked in.\n";
    }

    const std::string& name() const
    {
        return name_;
    }

private:
    std::string name_;
};

class Developer : public Employee
{
public:
    Developer(std::string name, std::string language)
        : Employee{std::move(name)},
          language_{std::move(language)}
    {
        std::cout << "Developer constructor: "
                  << language_ << '\n';
    }

    void writeCode() const
    {
        std::cout << name()
                  << " writes "
                  << language_
                  << " code.\n";
    }

private:
    std::string language_;
};

int main()
{
    Developer developer{"Maya", "C++20"};

    developer.clockIn();
    developer.writeCode();

    return 0;
}