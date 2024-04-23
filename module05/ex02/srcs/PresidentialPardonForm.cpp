//
// Created by ldiogo on 3/4/24.
//

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm()
{
	this->name = "Presidential Pardon Form";
	this->gradeToSign = 25;
	this->gradeToExecute = 5;
	this->target = target;
	this->isSigned = false;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw PresidentialPardonForm::FormNotSignedException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}