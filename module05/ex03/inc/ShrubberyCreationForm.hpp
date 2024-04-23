//
// Created by ldiogo on 3/4/24.
//

#ifndef INC_42_CPP_SHRUBBERYCREATIONFORM_HPP
#define INC_42_CPP_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>
#include <unistd.h>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const std::string &target);
	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
	class FileNotOpenException : public std::exception {
		const char *what() const throw() {
			return "File could not be opened";
		}
	};
};


#endif //INC_42_CPP_SHRUBBERYCREATIONFORM_HPP
