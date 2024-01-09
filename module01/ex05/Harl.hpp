//
// Created by Lourenco on 08/01/2024.
//

#ifndef INC_42CPP_HARL_HPP
#define INC_42CPP_HARL_HPP


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
