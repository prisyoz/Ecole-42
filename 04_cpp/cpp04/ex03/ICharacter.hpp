/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:27:16 by pang              #+#    #+#             */
/*   Updated: 2026/05/17 15:27:16 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual	std::string const &	getName() const = 0;
		virtual	void		equip(AMateria* m) = 0;
		virtual void		unequip(int idx) = 0;
		virtual void		use(int idx, ICharacter& target) = 0;
};

#endif