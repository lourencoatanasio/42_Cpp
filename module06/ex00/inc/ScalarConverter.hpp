//
// Created by ldiogo on 3/7/24.
//

#ifndef INC_42_CPP_SCALARCONVERTER_HPP
#define INC_42_CPP_SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <limits>

const double inf = std::numeric_limits<double>::infinity();

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	void	convertChar(const double& literal);
	void	convertInt(const double& literal);
	void	convertFloat(const double& literal);
	void	convertDouble(const double& literal);
public:
	static void convert(const std::string& literal);
	class ImpossibleException : public std::exception { // Inherit publicly from std::exception
	public:
		const char* what() const throw(); // Override what() method
	};
};


#endif //INC_42_CPP_SCALARCONVERTER_HPP
