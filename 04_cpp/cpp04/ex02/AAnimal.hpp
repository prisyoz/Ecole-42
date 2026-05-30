/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:25:38 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:25:38 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class	AAnimal
{
	protected:
		std::string type;
		
	public:
		AAnimal();
		AAnimal(const AAnimal& original);
		AAnimal& operator=(const AAnimal& original);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;
		virtual std::string	getIdea(unsigned int index) const;
};

#endif