//
// Created by ldiogo on 3/4/24.
//

#ifndef INC_42_CPP_SHRUBBERYCREATIONFORM_HPP
#define INC_42_CPP_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	ShrubberyCreationForm(const std::string &target);
	void execute(const Bureaucrat &executor) const;
	std::string getTarget() const;
	class FormNotSignedException : public std::exception {
		const char *what() const throw() {
			return "Form is not signed";
		}
	};
	class FileNotOpenException : public std::exception {
		const char *what() const throw() {
			return "File could not be opened";
		}
	};
};


#endif //INC_42_CPP_SHRUBBERYCREATIONFORM_HPP
