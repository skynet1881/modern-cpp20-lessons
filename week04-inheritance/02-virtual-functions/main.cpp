#include <iostream>
#include <string_view>

class Notification
{
public:
    virtual ~Notification() = default;

    virtual void send(std::string_view message) const
    {
        std::cout << "Generic notification: "
                  << message
                  << '\n';
    }
};

class EmailNotification : public Notification
{
public:
    void send(std::string_view message) const override
    {
        std::cout << "Email: "
                  << message
                  << '\n';
    }
};

class SmsNotification : public Notification
{
public:
    void send(std::string_view message) const override
    {
        std::cout << "SMS: "
                  << message
                  << '\n';
    }
};

void notifyUser(
    const Notification& notification,
    std::string_view message)
{
    notification.send(message);
}

int main()
{
    EmailNotification email;
    SmsNotification sms;

    notifyUser(email, "Your order has shipped.");
    notifyUser(sms, "Your verification code is 1234.");

    return 0;
}