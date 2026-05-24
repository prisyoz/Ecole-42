#include "Harl.hpp"

int main(void)
{
    Harl    harl;

    std::cout << "1: ";
    harl.complain("DEBUG");
    std::cout << "2: ";
    harl.complain("ERROR");
    std::cout << "3: ";
    harl.complain("WARNING");
    std::cout << "4: ";
    harl.complain("INFO");
    std::cout << "5: ";
    harl.complain("TEST");

    return (0);
}