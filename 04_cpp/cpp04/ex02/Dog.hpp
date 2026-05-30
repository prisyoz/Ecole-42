/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:26:07 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:26:07 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
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