//
// Created by ldiogo on 3/4/24.
//

#ifndef INC_42_CPP_PRESIDENTIALPARDONFORM_HPP
#define INC_42_CPP_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	PresidentialPardonForm(const std::string &target);
	void execute(const Bureaucrat &executor) const;
	std::string getTarget() const;
	class FormNotSignedException : public std::exception {
		const char *what() const throw() {
			return "Form is not signed";
		}
	};
};


#endif //INC_42_CPP_PRESIDENTIALPARDONFORM_HPP
