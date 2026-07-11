/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:23:47 by pang              #+#    #+#             */
/*   Updated: 2026/07/02 21:16:42 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <climits>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cmath>

class ScalarConverter
{
	public:
		enum	Type
		{
			CHAR,
			INT,
			DOUBLE,
			FLOAT,
			INVALID
		};
		
		static void	convert(const std::string& str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& original);
		ScalarConverter& operator=(const ScalarConverter& original);
		~ScalarConverter();

		static Type	detectType(const std::string& str);
		static void	char_convert(const std::string& str);
		static void	int_convert(const std::string& str);
		static void	float_convert(const std::string& str);
		static void	double_convert(const std::string& str);
};

#endif

// static - no instantiation, no memory overhead