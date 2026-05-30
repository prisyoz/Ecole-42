/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:24:51 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:24:51 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat& original);
		Cat& operator=(const Cat& original);
		~Cat();

		void		makeSound() const;
		Cat&		setCatIdea(unsigned int index, std::string idea);
		std::string	getIdea(unsigned int index) const;
};

#endif