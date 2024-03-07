//
// Created by ldiogo on 3/7/24.
//

#ifndef INC_42_CPP_INTERN_HPP
#define INC_42_CPP_INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	AForm *makeForm(const std::string &form, const std::string &target);
	AForm *makeShrubberyCreationForm(const std::string &target);
	AForm *makeRobotomyRequestForm(const std::string &target);
	AForm *makePresidentialPardonForm(const std::string &target);
	class FormNotFoundException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form not found";
		}
	};
};

#endif //INC_42_CPP_INTERN_HPP
