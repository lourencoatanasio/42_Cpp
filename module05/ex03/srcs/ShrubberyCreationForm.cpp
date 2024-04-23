//
// Created by ldiogo on 3/4/24.
//

#include "../inc/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm()
{
	this->name = "Shrubbery Creation Form";
	this->gradeToSign = 145;
	this->gradeToExecute = 137;
	this->target = target;
	this->isSigned = false;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	if (!this->getIsSigned())
		throw ShrubberyCreationForm::FormNotSignedException();

	std::ofstream file((this->getTarget() + "_shrubbery").c_str()); // Open file
	if (!file.is_open()) {
		throw ShrubberyCreationForm::FileNotOpenException(); // Throw exception if file cannot be opened
	}

    srand(time(NULL) ^ (getpid() << 16));

    if(rand() % 2 == 0) {
        file << "      /\\      " << std::endl;
        file << "     /\\*\\     " << std::endl;
        file << "    /\\O\\*\\    " << std::endl;
        file << "   /*/\\/\\/\\   " << std::endl;
        file << "  /\\O\\/\\*\\/\\  " << std::endl;
        file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
        file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        file << std::endl;
    } else {
        file << "       ^       " << std::endl;
        file << "      ^^^      " << std::endl;
        file << "     ^^^^^     " << std::endl;
        file << "    ^^^^^^^    " << std::endl;
        file << "   ^^^^^^^^^   " << std::endl;
        file << "  ^^^^^^^^^^^  " << std::endl;
        file << " ^^^^^^^^^^^^^ " << std::endl;
        file << "^^^^^^^^^^^^^^^" << std::endl;
        file << "      |||      " << std::endl;
        file << "      |||      " << std::endl;
        file << std::endl;
    }
	// Write to file

	file.close(); // Close file
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}