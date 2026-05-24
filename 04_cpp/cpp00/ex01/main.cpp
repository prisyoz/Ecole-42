#include "PhoneBook.hpp"

// empty phonebook
int	main(int argc, char **argv)
{
	(void)argv;
	PhoneBook	phoneBook;
	
	if (argc != 1)
	{
		std::cout << "Just run the program only!" << std::endl;
		return (1);
	}
	phoneBook.show_menu();
	
	return (0);
}

void	PhoneBook::show_menu()
{
	std::string	choice;
	
	while (!std::cin.eof())
	{
		std::cout << "Welcome to your Crappy Phonebook!\nWhat would you like to do?\n" << std::endl;
		std::cout << "1) Add a contact\n2) Search a contact\n3) Exit\n" << std::endl;
		
		std::getline(std::cin, choice);
		// this needs to be only 1 number. not 1a or 11 etc
		if (choice.length() == 1 && choice == "1")
		{
			this->add();
		}
		else if (choice.length() == 1 && choice == "2")
			this->search();
		else if (choice.length() == 1 && choice == "3")
		{
			std::cout << "Say goodbye to your contacts! Ciao~" << std::endl;
			break ;
		}
		else
		{
			std::cout << "No such choice la!\n" << std::endl;
			usleep(1000000);
		}
	}
}
