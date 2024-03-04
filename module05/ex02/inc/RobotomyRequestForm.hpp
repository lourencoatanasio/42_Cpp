//
// Created by ldiogo on 3/4/24.
//

#ifndef INC_42_CPP_ROBOTOMYREQUESTFORM_HPP
#define INC_42_CPP_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	RobotomyRequestForm(const std::string &target);
	void execute(const Bureaucrat &executor) const;
	std::string getTarget() const;
	class FormNotSignedException : public std::exception {
		const char *what() const throw() {
			return "Form is not signed";
		}
	};
};


#endif //INC_42_CPP_ROBOTOMYREQUESTFORM_HPP
