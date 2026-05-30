#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_learnedMaterias[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& original)
{
	for (int i = 0 ; i < 4; i++)
	{
		if (original._learnedMaterias[i] != NULL)
			this->_learnedMaterias[i] = original._learnedMaterias[i]->clone();
		else
			this->_learnedMaterias[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& original)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &original)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_learnedMaterias[i])
			{
				delete (this->_learnedMaterias[i]);
				this->_learnedMaterias[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (original._learnedMaterias[i])
				this->_learnedMaterias[i] = original._learnedMaterias[i]->clone();
			else
				this->_learnedMaterias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnedMaterias[i] != NULL)
		{
			delete (this->_learnedMaterias[i]);
			this->_learnedMaterias[i] = NULL;
		}
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnedMaterias[i] == NULL)
		{
			this->_learnedMaterias[i] = m;
			return ;
		}
	}
	std::cout << "Learned Materias full" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learnedMaterias[i] && _learnedMaterias[i]->getType() == type)
			return (_learnedMaterias[i]->clone());
	}
	return (0);
}

void	MateriaSource::printMateria() const
{
	std::cout << "\nLearn Materia\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnedMaterias[i] != NULL)
			std::cout << i << ": " << this->_learnedMaterias[i]->getType() << std::endl;
		else
			std::cout << i << ": Empty" << std::endl;
	}
}
