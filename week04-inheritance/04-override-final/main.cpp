#include <iostream>
#include <string_view>

class Logger
{
public:
    virtual ~Logger() = default;

    virtual void write(std::string_view message) const
    {
        std::cout
            << "[Logger] "
            << message
            << '\n';
    }
};

class ConsoleLogger : public Logger
{
public:
    void write(std::string_view message) const override final
    {
        std::cout
            << "[Console] "
            << message
            << '\n';
    }
};

class ColoredConsoleLogger : public ConsoleLogger
{
public:
    void setColor() const
    {
        std::cout << "Changing console color...\n";
    }

    // ERROR:
    //
    // void write(std::string_view message) const override
    // {
    // }
    //
    // ConsoleLogger::write() is final.
};

class NullLogger final : public Logger
{
public:
    void write(std::string_view) const override
    {
        // Intentionally ignore all log messages.
    }
};

void logMessage(
    const Logger& logger,
    std::string_view message)
{
    logger.write(message);
}

int main()
{
    ConsoleLogger console;
    NullLogger nullLogger;

    logMessage(console, "Application started");
    logMessage(nullLogger, "This will not be displayed");

    return 0;
}