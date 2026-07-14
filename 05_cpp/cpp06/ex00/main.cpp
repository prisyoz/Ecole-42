#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "1 argument only\n";
		return 1;
	}
	else
	{
		ScalarConverter::convert(argv[1]);
	}
	return 0;	
}



// int min, int max (bigger, smaller)
// float min, float max (bigger, smaller)

/* int_min = -2147483648
int_max = 2147483647
float_min = 1.17549435e-38F
float_max = 3.40282347e+38F
dbl_min = 1.79769313486231571e+308
dbl_max = 2.22507385850720138e-308
 */