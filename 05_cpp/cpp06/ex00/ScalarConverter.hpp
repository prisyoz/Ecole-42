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