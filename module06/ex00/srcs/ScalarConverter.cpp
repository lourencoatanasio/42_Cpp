//
// Created by ldiogo on 3/7/24.
//

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

void ScalarConverter::convertChar(const double &literal)
{
	try
	{
		char c = static_cast<char>(literal);
		if (c < 32 || c > 126)
			throw ImpossibleException();
		std::cout << "char: '" << c << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}

bool isNaN(double x) {
	return x != x;
}

bool isInf(double x) {
	return x == HUGE_VAL || x == -HUGE_VAL;
}

void ScalarConverter::convertInt(const double &literal)
{
	try
	{
		if (isNaN(literal) || literal > INT_MAX || literal < INT_MIN || isInf(literal))
			throw ImpossibleException();
		int i = static_cast<int>(literal);
		std::cout << "int: " << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

bool isInteger(double number) {
	return (number - static_cast<int>(number)) < 1e-10;
}

void ScalarConverter::convertFloat(const double &literal)
{
	try
	{
		if (literal > FLT_MAX || literal < -FLT_MAX)
			throw ImpossibleException();
		float f = static_cast<float>(literal);
		if(isInteger(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::convertDouble(const double &literal)
{
	std::cout.precision(15);
	try
	{
		if (literal > DBL_MAX || literal < -DBL_MAX)
			throw ImpossibleException();
		double d = static_cast<double>(literal);
		if(isInteger(d))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	double d;
	double inf = std::numeric_limits<double>::infinity();


	d = std::atof(literal.c_str());
	if (d == 0 && literal[0] != '0')
	{
		d = static_cast<double>(literal[0]);
		if (literal.length() != 1 || !std::isprint(d)) {
			throw ImpossibleException();
		}
	}
	if(d == inf)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if(d == -inf)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}
	ScalarConverter converter;
	converter.convertChar(d);
	converter.convertInt(d);
	converter.convertFloat(d);
	converter.convertDouble(d);
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "Invalid input.";
}