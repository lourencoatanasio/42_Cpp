//
// Created by ldiogo on 2/29/24.
//

#ifndef INC_42_CPP_BUREAUCRAT_HPP
#define INC_42_CPP_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
	std::string name;
	int grade;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void	signForm(class AForm &form);
	void	executeForm(class AForm &form);
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade is too high";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw() {
			return "Grade from bureaucrat is too low";
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //INC_42_CPP_BUREAUCRAT_HPP
