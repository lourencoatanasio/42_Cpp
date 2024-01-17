#include "../inc/header.hpp"

bool	isStringDigit(std::string str)
{
	for (long unsigned int i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	isStringAlpha(std::string str)
{
	for (long unsigned int i = 0; i < str.length(); ++i)
	{
		if (!std::isalpha(str[i]))
			return false;
	}
	return true;
}

bool	isStringAlphaNumeric(std::string str)
{
    for (long unsigned int i = 0; i < str.length(); ++i)
    {
        if (!std::isalnum(str[i]))
            return false;
    }
    return true;
}