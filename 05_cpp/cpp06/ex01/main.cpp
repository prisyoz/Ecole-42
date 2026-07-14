#include "Serialize.hpp"

int main(void)
{
	Data a;
	a.num = 42;

	std::cout << "a: " << &a << std::endl;

	// becomes a integer type
	uintptr_t mem = serializer::serialize(&a);
	std::cout << "mem: " << mem << std::endl;

	// mem is integer type
	Data* p = serializer::deserialize(mem);
	std::cout << "p: " << p << std::endl;

	if (p == &a)
		std::cout << "Yay! It's the same!" << std::endl;
	else
		std::cout << "Not the same!" << std::endl;

	std::cout << "\n=== Modified data ===\n";
	a.num = 100;
	Data *p2 = serializer::deserialize(mem);
	std::cout << "p1->num: " << p->num << std::endl;
	std::cout << "p1: " << p << std::endl;
	std::cout << "p2->num: " << p2->num << std::endl;
	std::cout << "p2: " << p2 << std::endl;

	Data b;
	b.num = 99;
	uintptr_t mem2 = serializer::serialize(&b);
	Data* p3 = serializer::deserialize(mem2);
	std::cout << "p3 == &b: " << (p3 == &b) << std::endl;
	std::cout << "p3 != &a: " << (p3 != &a) << std::endl;

	return 0;
}