/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:25:48 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:25:48 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "AAnimal.hpp"

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain& original);
		Brain& operator=(const Brain& original);
		~Brain();

		void		setIdeas(unsigned int index, std::string idea);
		std::string	getIdeas(unsigned int index);
};

#endif