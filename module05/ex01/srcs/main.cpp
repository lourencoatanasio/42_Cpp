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
	Bureaucrat b1("Senhor Burocrata", 75);
	std::cout << b1 << std::endl; // bureaucrat info
	f2.signForm(b1);
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================

	// Bureaucrat with sufficient grade ========================================
	Bureaucrat b2("Burocrata melhor", 30);
	std::cout << b2 << std::endl; // bureaucrat info
	f2.signForm(b2);
	std::cout << f2 << std::endl;
	std::cout << std::endl;
	// =========================================================================
}