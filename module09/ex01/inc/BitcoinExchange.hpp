//
// Created by ldiogo on 4/8/24.
//

#ifndef INC_42_CPP_BITCOINEXCHANGE_HPP
#define INC_42_CPP_BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <exception>

class BitcoinExchange {
private:
    std::map<std::string, float> values;
    std::map<std::string, float> lines;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    class InvalidDateException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif //INC_42_CPP_BITCOINEXCHANGE_HPP
