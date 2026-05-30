#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#include <iostream>

class MateriaSource : public IMateriaSource
{

	private:
		AMateria* _learnedMaterias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& original);
		MateriaSource& operator=(const MateriaSource& original);
		virtual ~MateriaSource();

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
		void				printMateria() const;
};


#endif