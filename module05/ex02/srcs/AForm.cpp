//
// Created by ldiogo on 2/29/24.
//

#include "../inc/AForm.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(1), gradeToExecute(1) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &form) : name(form.name), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
	*this = form;
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &form) {
	if (this == &form)
		return *this;
	this->isSigned = form.isSigned;
	return *this;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::signForm(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
	std::cout << bureaucrat.getName() << " signs " << name << std::endl;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() << " is " << (form.getIsSigned() ? "" : "not ") << "signed and its grade requirements are " << form.getGradeToSign() << " to sign and " << form.getGradeToExecute() << " to execute." << std::endl;
	return os;
}