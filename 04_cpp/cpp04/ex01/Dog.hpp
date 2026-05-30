/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:24:59 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:24:59 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*brain;
		
	public:
		Dog();
		Dog(const Dog& original);
		Dog& operator=(const Dog& original);
		~Dog();

		void		makeSound() const;
		Dog&		setDogIdea(unsigned int index, std::string idea);
		std::string	getIdea(unsigned int index) const;
};

#endif