/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:22:56 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:22:56 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string type;
		
	public:
		Animal();
		Animal(const Animal& original);
		Animal& operator=(const Animal& original);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;

};

#endif