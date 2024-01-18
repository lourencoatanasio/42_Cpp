#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "Este debug é podre lol" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Esta info é podre lol ajuda-me" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Este warning é podre lol, oh não!" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Este error é podre lol, devia ser melhor" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
        {
			(this->*functions[i])();
            return;
        }
	}
	std::cout << "Se não dizes nada do que eu sei eu não reclamo." << std::endl;
}