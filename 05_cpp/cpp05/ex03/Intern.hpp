/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:18:37 by pang              #+#    #+#             */
/*   Updated: 2026/07/01 16:18:37 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& original);
		Intern& operator=(const Intern& original);
		~Intern();

		AForm*	makeForm(std::string form, std::string target);
};



#endif