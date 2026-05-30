#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("unknown"), _dropCount(0)
{
	for (int i = 0; i < 4; i++)
		_invent[i] = NULL;
	for (int i = 0; i < MAX_DROPPED; i++)
		_dropped[i] = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const name) : _name(name), _dropCount(0)
{
	for (int i = 0; i < 4; i++)
		_invent[i] = NULL;
	for (int i = 0; i < MAX_DROPPED; i++)
		_dropped[i] = NULL;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& original) : _name(original._name), _dropCount(original._dropCount)
{
	for (int i = 0; i < 4; i++)
		this->_invent[i] = NULL;
	for (int i = 0; i < MAX_DROPPED; i++)
		this->_dropped[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (original._invent[i])
			this->_invent[i] = original._invent[i]->clone();
	}
	for (int i = 0; i < MAX_DROPPED; i++)
	{
		if (original._dropped[i])
			this->_dropped[i] = original._dropped[i]->clone();
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& original)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &original)
	{
		this->_name = original._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_invent[i])
			{
				delete (this->_invent[i]);
				this->_invent[i] = NULL;
			}
		}
		for (int i = 0; i < MAX_DROPPED; i++)
		{
			delete (this->_dropped[i]);
			this->_dropped[i] = NULL;
		}
		this->_dropCount = original._dropCount;
		for (int i = 0; i < 4; i++)
			if (original._invent[i])
				this->_invent[i] = original._invent[i]->clone();
		for (int i = 0; i < _dropCount; i++)
			if (original._dropped[i])
				this->_dropped[i] = original._dropped[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete (this->_invent[i]);
		this->_invent[i] = NULL;
	}
	for (int i = 0; i < MAX_DROPPED; i++)
	{
		delete (this->_dropped[i]);
		this->_dropped[i] = NULL;
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	
	for (int i = 0; i < 4; i++)
	{
		if (_invent[i] == NULL)
		{
			_invent[i] = m;
			return ;
		}
	}
	std::cout << "Full slot, cannot equip" << std::endl;
	if (_dropCount < MAX_DROPPED)
		_dropped[_dropCount++] = m;
	else
		delete m;
}

void	Character::unequip(int idx)
{
	if  (idx >= 0 && idx <= 3 && _invent[idx] && _dropCount < MAX_DROPPED)
	{
		_dropped[_dropCount] = _invent[idx];
		_dropCount++;
		_invent[idx] = NULL;
	}
	else
		std::cout << "Inventory " << idx << ": Cannot unequip" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_invent[idx] != NULL)
		this->_invent[idx]->use(target);
}

void	Character::printInventory() const
{
	std::cout << "\nInventory\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_invent[i] != NULL)
			std::cout << i << ": " << this->_invent[i]->getType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}

	std::cout << "Dropped inventory\n";
	for (int i = 0; i < MAX_DROPPED; i++)
	{
		if (this->_dropped[i] != NULL)
			std::cout << i << ": " << this->_dropped[i]->getType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}

