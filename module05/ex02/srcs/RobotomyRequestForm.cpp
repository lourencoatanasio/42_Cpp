//
// Created by ldiogo on 3/4/24.
//

#include <stdlib.h>
#include <unistd.h>
#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm()
{
	this->name = "Robotomy Request Form";
	this->gradeToSign = 72;
	this->gradeToExecute = 45;
	this->target = target;
	this->isSigned = false;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	srand(time(NULL) ^ (getpid() << 16));
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw RobotomyRequestForm::FormNotSignedException();
	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << target << " failed to be robotomized" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}