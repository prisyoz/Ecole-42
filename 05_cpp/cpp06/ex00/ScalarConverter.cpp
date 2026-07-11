/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:23:43 by pang              #+#    #+#             */
/*   Updated: 2026/07/11 21:45:01 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
	(void)original;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original)
{
	(void)original;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


ScalarConverter::Type	ScalarConverter::detectType(const std::string& str)
{
	char	*end;

	if ((str.length() == 3 && str[0] == '\'' && str[2] == '\'') || (str.length() == 1 && !std::isdigit(str[0])))
		return CHAR;
	
	if (str == "nanf" || str == "-inff" || str == "+inff")
		return FLOAT;

	if (str == "nan" || str == "-inf" || str == "+inf")
		return DOUBLE;

	double	val = std::strtod(str.c_str(), &end);

	if (end != str.c_str())
	{
		if (*end == 'f' && *(end + 1) == '\0')
		{
			if (val < -std::numeric_limits<float>::max() || val > std::numeric_limits<float>::max())
				return DOUBLE;
			return FLOAT;
		}
		if (*end == '\0')
		{
			if (str.find('.') != std::string::npos || val < INT_MIN || val > INT_MAX)
				return DOUBLE;
			return INT;
		}
	}
	return INVALID;
}

// static_cast <dest_type> (source);

void	ScalarConverter::char_convert(const std::string& str)
{
	char c;
	
	if (str.length() == 3 && str[0] == '\'')
		c = str[1];
	else
		c = str[0];

	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: "
		<< static_cast<float>(c) << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "double: "
		<< static_cast<double>(c) << std::endl;
}

void	ScalarConverter::int_convert(const std::string& str)
{
	std::istringstream	iss(str);
	int					i;

	iss >> i;
	if (iss.fail() || iss.eof())

	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible" << std::endl;
		return ;
	}

	if (i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: "
		<< static_cast<float>(i) << "f" << std::endl;
	
	std::cout << std::fixed << std::setprecision(1) << "double: " 
		<< static_cast<double>(i) << std::endl;
}

void	ScalarConverter::float_convert(const std::string& str)
{
	if (str == "nanf")
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}

	if (str == "+inff")
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: +inff\ndouble: +inf" << std::endl;
        return ;
	}
	if (str == "-inff")
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: -inff\ndouble: -inf" << std::endl;
        return ;
	}

	// remove the potential "f"
	std::string clean_str = str;
	if (!clean_str.empty() && clean_str[clean_str.length() - 1] == 'f')
		clean_str.erase(clean_str.length() - 1);

	std::istringstream	iss(clean_str);
	float	i;

	if (!(iss >> i))
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible" << std::endl;
		return ;
	}

	if (i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	if (i < static_cast<float>(INT_MIN) || i > static_cast<float>(INT_MAX))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "float: " << i << "f" << std::endl;
	
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
}

void	ScalarConverter::double_convert(const std::string& str)
{
	if (str == "nan")
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return ;
	}

	if (str == "+inf")
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: +inff\ndouble: +inf" << std::endl;
		return ;
	}
	if (str == "-inf")
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: -inff\ndouble: -inf" << std::endl;
		return ;
	}
	
	std::istringstream	iss(str);
	double				i;

	if (!(iss >> i))
	{
		std::cout << "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible" << std::endl;
		return ;
	}

	if (i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	if (i < static_cast<double>(INT_MIN) || i > static_cast<double>(INT_MAX))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(i) << std::endl;

	if (i < -std::numeric_limits<float>::max() || i > std::numeric_limits<float>::max())
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << i << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(1) << "double: " << i << std::endl;
}

void	ScalarConverter::convert(const std::string& str)
{

	ScalarConverter::Type type = ScalarConverter::detectType(str);

	switch (type)
	{
		case ScalarConverter::CHAR:
		{
			ScalarConverter::char_convert(str);
			break ;
		}
		case ScalarConverter::INT:
		{
			ScalarConverter::int_convert(str);
			break ;
		}
		case ScalarConverter::FLOAT:
		{
			ScalarConverter::float_convert(str);
			break ;
		}

		case ScalarConverter::DOUBLE:
		{
			ScalarConverter::double_convert(str);
			break ;
		}
		default:
		{
			std::cout << "Impossible to convert" << std::endl;
			break ;
		}
	}
}
