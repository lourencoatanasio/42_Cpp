//
// Created by ldiogo on 2/29/24.
//

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this == &bureaucrat)
		return *this;
	this->grade = bureaucrat.grade;
	return *this;
}

void Bureaucrat::incrementGrade() {
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}