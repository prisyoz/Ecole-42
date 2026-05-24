#include "Zombie.hpp"

// constructor
Zombie::Zombie(std::string name) : _name(name) {}

// deconstructor
Zombie::~Zombie()
{
    std::cout << _name << ": is destroyed!" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
