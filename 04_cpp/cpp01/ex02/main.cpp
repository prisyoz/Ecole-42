#include <iostream>

int main()
{
    // string variable
    std::string brainz = "HI THIS IS BRAIN";
    std::string *ptr = &brainz;
    std::string &ref = brainz;

    std::cout << "string mem add: " << &brainz << std::endl;
    std::cout << "stringPTR mem add: " << ptr << std::endl;
    std::cout << "stringREF mem add: " << &ref << "\n" << std::endl;

    std::cout << "string variable: " << brainz << std::endl;
    std::cout << "stringPTR value: " << *ptr << std::endl;
    std::cout << "stringREF value: " << ref << std::endl;
}