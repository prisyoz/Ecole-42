/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:26:21 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:26:21 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string		type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& original);
		WrongAnimal& operator=(const WrongAnimal& original);
		virtual ~WrongAnimal();

		virtual void makeSound() const;
		std::string		getType() const;
};

#endif