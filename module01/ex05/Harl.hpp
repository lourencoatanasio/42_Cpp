#ifndef INC_42CPP_HARL_HPP
#define INC_42CPP_HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	void	complain(std::string level);
};


#endif //INC_42CPP_HARL_HPP
