//
// Created by ldiogo on 4/8/24.
//

#include "../inc/BitcoinExchange.hpp"

bool is_all_digit(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]) && str[i] != '.') {
            return false;
        }
    }
    return true;
}

void   check_valid_date(const std::string &date)
{
    std::cout << date << std::endl;
    if(date.length() != 10)
        throw std::invalid_argument("Invalid date format 1");
    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Invalid date format 2");
    if (!is_all_digit(date.substr(0, 4)) || !is_all_digit(date.substr(5, 2)) || !is_all_digit(date.substr(8, 2)))
        throw std::invalid_argument("Invalid date format 3");
    int day = std::atoi(date.substr(8, 2).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int year = std::atoi(date.substr(0, 4).c_str());
    if (day < 1 || month < 1 || month > 12 || year < 1)
        throw std::invalid_argument("Invalid date format 4");
    if (month == 2 && day > 29 && (year % 4 == 0))
        throw std::invalid_argument("Invalid date format 5");
    if (month == 2 && day > 28 && (year % 4 != 0))
        throw std::invalid_argument("Invalid date format 6");
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::invalid_argument("Invalid date format 7");
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        throw std::invalid_argument("Invalid date format 8");
    return ;
}

int    check_valid_value_source(const std::string &value)
{
    std::cout << value << std::endl;
    if(!is_all_digit(value))
        throw std::invalid_argument("Invalid value");
    float val = std::atof(value.c_str());
    if (val < 0)
        throw std::invalid_argument("Invalid value");
    return 0;
}

int    check_valid_value(const std::string &value)
{
    std::cout << value << std::endl;
    if(!is_all_digit(value))
        throw std::invalid_argument("Invalid value");
    float val = std::atof(value.c_str());
    if (val < 0)
        throw std::invalid_argument("Invalid value");
    else if (val > 1000)
        throw std::invalid_argument("Invalid value");
    return 0;
}

bool    check_pipe(std::string &line)
{
    int pipe_count = 0;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '|')
            pipe_count++;
    }
    if (pipe_count != 1)
        throw std::invalid_argument("Invalid input file");
    return true;
}

std::map<std::string, float> get_file_input(const std::string &fileName, std::map<std::string, float>& lines)
{
    std::ifstream file(fileName.c_str());
    std::string line;

    if (!file.is_open())
        throw std::invalid_argument("Invalid input file");
    while (std::getline(file, line))
    {
        try {
            check_pipe(line);
            check_valid_date(line.substr(0, 10));
            check_valid_value(line.substr(11, line.size() - 11));
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return lines;
        }
    }
    file.close();
    return lines;
}

bool    check_comma(std::string &line)
{
    int comma_count = 0;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
            comma_count++;
    }
    if (comma_count != 1)
        throw std::invalid_argument("Invalid input file");
    return true;
}

std::map<std::string, float> get_value_input(const std::string &fileName, std::map<std::string, float>& lines)
{
    std::ifstream file(fileName.c_str());
    std::string line;

    if (!file.is_open())
        throw std::invalid_argument("Invalid input file");
    std::getline(file, line);
    while (std::getline(file, line))
    {
        try {
            check_comma(line);
            check_valid_date(line.substr(0, 10));
            check_valid_value_source(line.substr(11, line.size() - 11));
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return lines;
        }
    }
    file.close();
    return lines;
}

BitcoinExchange::BitcoinExchange()
{
    try
    {
        values = get_value_input("data.csv", values);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return *this;
    return *this;
}