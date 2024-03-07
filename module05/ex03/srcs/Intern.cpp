//
// Created by ldiogo on 3/7/24.
//

#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &form, const std::string &target) {
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (Intern::*functions[3])(const std::string &target) = {
			&Intern::makeShrubberyCreationForm,
			&Intern::makeRobotomyRequestForm,
			&Intern::makePresidentialPardonForm
	};

	for(int i = 0; i < 3; i++) {
		if (form == forms[i]) {
			return (this->*(functions[i]))(target);
		}
	}
	throw Intern::FormNotFoundException();
}
