//
// Created by ldiogo on 2/29/24.
//

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
	// Form with grade requirements out of bonds ===============================
	try
	{
		std::cout << "Trying to create a Form with grade requirements out of bonds" << std::endl;
		Form f1("f2", -1, 1);
//		Form f1("f1", 27, 172);
//		Form f1 ("f1", 0, 234);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// =========================================================================

	// Show Form attributes ====================================================
	std::cout << std::endl;
	Form f2;
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================

	// Bureaucrat without sufficient grade =====================================
	try
	{
		Bureaucrat b1("Senhor Burocrata", 75);
		std::cout << b1 << std::endl; // bureaucrat info
        b1.signForm(f2);
		std::cout << f2 << std::endl;
		std::cout << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// =========================================================================

	// Bureaucrat with sufficient grade ========================================
	try
	{
		Bureaucrat b2("Burocrata melhor", 30);
		std::cout << b2 << std::endl; // bureaucrat info
		f2.beSigned(b2);
		std::cout << f2 << std::endl;
		std::cout << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// =========================================================================

	try
	{
		Bureaucrat b3("Burocrata bom", 25);
		std::cout << b3 << std::endl; // bureaucrat info
		Form f3("f3", 25, 30);
		b3.signForm(f3);
		std::cout << f3 << std::endl;
		std::cout << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
}