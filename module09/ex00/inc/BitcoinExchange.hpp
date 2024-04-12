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
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    void    makeExchange(const std::string &date, const std::string &value);
    class InvalidDateException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

bool    check_pipe(std::string &line);
int    check_valid_value(const std::string &value);
void   check_valid_date(const std::string &date);

#endif //INC_42_CPP_BITCOINEXCHANGE_HPP
