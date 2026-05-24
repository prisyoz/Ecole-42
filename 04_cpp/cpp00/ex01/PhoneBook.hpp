#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <unistd.h>

class Contact
{
	public:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenum;
	std::string	dark_secret;
};

class PhoneBook
{
	private:
	Contact contacts[8];
	int	contact_count;
	int	next_index;

	public:
	PhoneBook();
	
	// functions
	void		add();
	Contact		new_contact();
	void		search();
	void		show_menu();
	std::string	format_col(const std::string str);
};

#endif