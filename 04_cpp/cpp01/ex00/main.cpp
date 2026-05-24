#include "Zombie.hpp"

int main()
{
    std::cout << "Arrival of Stack Zombie" << '\n';
    randomChump("Stacky");
	std::cout << "Say Goodbye!" << std::endl;
	std::cout << std::endl;

    std::cout << "Here comes the Heap Zombie" << std::endl;
    Zombie *heap = newZombie("Heapy");
    heap->announce();

    std::cout << "Say Goodbye!" << std::endl;
    delete heap;
    
    // many zombies
    std::cout << "\n\nMany zombies\n";
    std::string bunch[] = {"Jonny", "Stacky", "Clocky", "Jikky", "Junky"};
    for (int i = 0; i < 5; i++)
	{
        randomChump(bunch[i]);
	}
	
	std::cout << "\nZombies arriving in heap bunch\n";
	Zombie	*heapbunch[5];
	for (int i = 0; i < 5; i++)
	{
		heapbunch[i] = newZombie(bunch[i]);
		heapbunch[i]->announce();
	}
	for (int i = 0; i < 5; i++)
		delete heapbunch[i];

    return 0;
}
