//
// Created by ldiogo on 2/29/24.
//

#include "../inc/Form.hpp"

Form::Form() : name("formulary"), gradeToSign(35), gradeToExecute(15)
{
	isSigned = false;
	std::cout << "Form printed." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form) : name(form.name), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
	*this = form;
}

Form::~Form() {}

Form &Form::operator=(const Form &form) {
	if (this == &form)
		return *this;
	this->isSigned = form.isSigned;
	return *this;
}

std::string Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << " is " << (form.getIsSigned() ? "" : "not ") << "signed and its grade requirements are " << form.getGradeToSign() << " to sign and " << form.getGradeToExecute() << " to execute." << std::endl;
	return os;
}