//
// Created by ldiogo on 2/29/24.
//

#ifndef INC_42_CPP_AFORM_HPP
#define INC_42_CPP_AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"

class AForm {
protected:
	std::string name;
	std::string target;
	bool isSigned;
	int gradeToSign;
	int gradeToExecute;
public:
	AForm();
	AForm(const AForm &form);
	virtual ~AForm() = 0;
	AForm &operator=(const AForm &form);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
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
	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "The form is not signed.";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif //INC_42_CPP_FORM_HPP
