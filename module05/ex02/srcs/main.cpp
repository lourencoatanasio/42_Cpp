//
// Created by ldiogo on 2/29/24.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
	try // sign: 145 exec: 137
	{
		Bureaucrat b1("Senhor executor burocrata", 137);
		ShrubberyCreationForm f1("jardim");
		std::cout << f1 << std::endl << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);
		std::cout << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try // sign: 72 exec: 45
	{
		Bureaucrat b1("Senhor doutor", 45);
		AForm *f1 = new RobotomyRequestForm("paciente");
		std::cout << *f1 << std::endl << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
		std::cout << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	try // sign: 25 exec: 5
	{
		Bureaucrat b1("Burocrata de alto nivel", 5);
		AForm *f1 = new PresidentialPardonForm("krikit warrior");
		std::cout << *f1 << std::endl << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}