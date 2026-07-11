/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 22:32:55 by pang              #+#    #+#             */
/*   Updated: 2026/07/02 22:33:06 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

serializer::serializer() {}

serializer::serializer(const serializer& src) 
{
	(void)src;
}

serializer& serializer::operator=(const serializer& src)
{
	(void)src;
	return *this;
}

serializer::~serializer() {}

uintptr_t serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}