//
// Created by ldiogo on 2/29/24.
//

#ifndef INC_42_CPP_FORM_HPP
#define INC_42_CPP_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
	std::string const name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &form);
	~Form();
	Form &operator=(const Form &form);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "The grade is too high.";
		}

	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "The grade is too low.";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //INC_42_CPP_FORM_HPP
