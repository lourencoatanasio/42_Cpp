//
// Created by ldiogo on 3/12/24.
//

#include "../inc/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
