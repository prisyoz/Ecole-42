/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:33:00 by pang              #+#    #+#             */
/*   Updated: 2026/07/02 22:33:05 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

class serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);


	private:
		serializer();
		serializer(const serializer& src);
		serializer& operator=(const serializer& src);
		~serializer();
};

#endif