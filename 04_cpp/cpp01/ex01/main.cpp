#include "Zombie.hpp"

int main()
{
    std::cout << "Zombies attack!" << std::endl;

    int N = 5;
    Zombie  *horde = zombieHorde(N, "Chompy");
    for(int i = 0; i < N; i++)
        horde[i].announce();

    delete [] horde;
    return 0;
}
