#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_count(0), next_index(0) {}

void	PhoneBook::add()
{
	std::cout << "Adding a contact" << std::endl;

	if (contact_count < 8)
	{
		contacts[contact_count] = new_contact();
		contact_count++;
	}
	else
	{
		next_index = (next_index) % 8;
		contacts[next_index] = new_contact();
		next_index += 1;
	}
	return ;
}

Contact	PhoneBook::new_contact()
{
	Contact contact;

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, contact.firstname);
	while (contact.firstname.empty())
	{
		std::cout << "Don't your contact have a name?" << std::endl;
		std::getline(std::cin, contact.firstname);
	}

	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, contact.lastname);
	while (contact.lastname.empty())
	{
		std::cout << "Eh, got first name then have last name lar?" << std::endl;
		std::getline(std::cin, contact.lastname);
	}

	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, contact.nickname);
	while (contact.nickname.empty())
	{
		std::cout << "Don't forget the nickname!" << std::endl;
		std::getline(std::cin, contact.nickname);
	}

	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, contact.phonenum);
	while (contact.phonenum.empty())
	{
		std::cout << "Of course you need a phone number! That's what a phonebook is for!"  << std::endl;
		std::getline(std::cin, contact.phonenum);
	}

	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, contact.dark_secret);
	while (contact.dark_secret.empty())
	{
		std::cout << "Got to have some skeletons in the closet! hehe 😈" << std::endl;
		std::getline(std::cin, contact.dark_secret);
	}

	std::cout << "\n";
	std::cout << contact.firstname << "is in your phonebook\n" << std::endl;
	return (contact);
}

// sanitize string to make sure spaces are the same
std::string	PhoneBook::format_col(const std::string str)
{
	std::string	clean_str = str;

	for (size_t	i = 0; i < clean_str.length(); i++)
	{
		if (clean_str[i] >= 9 && clean_str[i] <= 13)
			clean_str[i] = ' ';
	}

	// handle 10 char
	if (clean_str.length() > 10)
		return (clean_str.substr(0, 9) + ".");
	return (clean_str);
}

void	PhoneBook::search()
{
	std::cout << "This is search function" << std::endl;
	
	std::string header_field[4] = {"Index", "First name", "Last name", "Nickname"};
	std::cout << "|";
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::right << std::setw(10) << header_field[i];
		std::cout << "|";
	}
	std::cout << std::endl;
	std::string line(45, '-');
	std::cout << line << std::endl;

	// loop throught the contacts
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << format_col(contacts[i].firstname) << "|";
		std::cout << std::right << std::setw(10) << format_col(contacts[i].lastname) << "|";
		std::cout << std::right << std::setw(10) << format_col(contacts[i].nickname) << "|\n";
	}
	std::cout << line << std::endl;

	// prompt user for number
	std::cout << "Whose number do you want to find out? " << std::endl;

	std::string	number;
	while (1)
	{
		std::getline(std::cin, number);
	
		if (number.length() == 1 && (number >= "0" && number <= "7"))
		{
			int option;
			std::stringstream choice(number);
			choice >> option;
			
			std::cout << "\nHere's the details of " << contacts[option].firstname << "\n";
			std::cout << "First name:    " << contacts[option].firstname << "\n";
			std::cout << "Last name:     " << contacts[option].lastname << "\n";
			std::cout << "Nickname:      " << contacts[option].nickname << "\n";
			std::cout << "Phone num:     " << contacts[option].phonenum << "\n";
			std::cout << "Dark Secret 😈: " << contacts[option].dark_secret << "\n";
			std::cout << "\n" << std::endl;
			usleep(1000000);
			break ;
		}
		else
		{
			std::cout << "Sorry, your crappy phonebook don't have such an option\n" << std::endl;
			usleep(1000000);
			continue;
		}
	}
	std::cout << "\n" << std::endl;
}
