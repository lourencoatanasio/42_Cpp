//
// Created by ldiogo on 4/8/24.
//

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
    try
    {
        BitcoinExchange bitcoinExchange;
        std::ifstream file(argv[1]);
        if (!file.is_open()) {
            std::cerr << "Error: Cannot open file." << std::endl;
            return 1;
        }
        std::string line;
        int i = 0;
        while(std::getline(file, line))
        {
            i++;
            try
            {
                std::cout << "\e[1;31m";
                check_pipe(line);
                check_valid_date(line.substr(0, 10));
                check_valid_value(line.substr(12, line.size() - 12));
                std::cout << "\e[0m";
            } catch (std::exception &e) {
                std::cout << "Line " << i << ": " << e.what() << std::endl;
                continue ;
            }
            bitcoinExchange.makeExchange(line.substr(0, 10), line.substr(12, line.size() - 12));
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
	return 0;
}
