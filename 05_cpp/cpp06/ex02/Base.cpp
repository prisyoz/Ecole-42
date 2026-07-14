#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

// randomly instantiates ABC and returns instance as 
// Base pointer
Base * generate(void)
{
	int choice = rand() % 3;

	if (choice == 0)
		return (new A());
	else if (choice == 1)
		return (new B());
	else
		return (new C());
	
}

// prints the actual type of the object pointed to by p: "A" "B" "C"
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p ptr: 'A'" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p ptr: 'B'" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p ptr: 'C'" << std::endl;
	else
		std::cout << "p ptr: invalid" << std::endl;
}

// prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "p ref: 'A'" << std::endl;
		return ;
	}
	catch(const std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "p ref: 'B'" << std::endl;
		return ;
	}
	catch(const std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "p ref: 'C'" << std::endl;
		return ;
	}
	catch(const std::exception&) {}
	
}