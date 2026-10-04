#include <iostream>

int next_ticket_number()
{
    static int ticket_number = 1000;
    ++ticket_number;
    
    return ticket_number;
}

int main()
{
    const int first_ticket = next_ticket_number();

    const int second_ticket = next_ticket_number();

    const int third_ticket = next_ticket_number();

    std::cout << "Ticket: " << first_ticket << '\n';
    std::cout << "Ticket: " << second_ticket << '\n';
    std::cout << "Ticket: " << third_ticket << '\n';

    {
        const int temporary_value = 42;

        std::cout << "Inside scope: " << temporary_value << '\n';
    }

    {
        const int temporary_value = 40;

        std::cout << "Inside scope: " << temporary_value << '\n';
    }

    // ERROR: out of scope, no longer exists
    // temporary_value = 0; 

    return 0;
}