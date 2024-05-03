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
    if(date.length() != 10)
        throw std::invalid_argument("Invalid date format");
    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Invalid date format");
    if (!is_all_digit(date.substr(0, 4)) || !is_all_digit(date.substr(5, 2)) || !is_all_digit(date.substr(8, 2)))
        throw std::invalid_argument("Invalid date format");
    int day = std::atoi(date.substr(8, 2).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int year = std::atoi(date.substr(0, 4).c_str());
    if (day < 1 || month < 1 || month > 12 || year < 1)
        throw std::invalid_argument("Invalid date format");
    if (month == 2 && day > 29 && (year % 4 == 0))
        throw std::invalid_argument("Invalid date format");
    if (month == 2 && day > 28 && (year % 4 != 0))
        throw std::invalid_argument("Invalid date format");
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::invalid_argument("Invalid date format");
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        throw std::invalid_argument("Invalid date format");
    return ;
}

int    check_valid_value_source(const std::string &value)
{
    if(!is_all_digit(value))
        throw std::invalid_argument("Invalid value");
    if(!isdigit(value[0]))
        throw std::invalid_argument("Invalid value");
    float val = std::atof(value.c_str());
    if (val < 0)
        throw std::invalid_argument("Invalid value");
    else if (val == 0 && value[0] != '0')
        throw std::invalid_argument("Invalid value");
    return 0;
}

int    check_valid_value(const std::string &value)
{
    if(value[0] != ' ')
        throw std::invalid_argument("Invalid value format");
    if(!is_all_digit(value.substr(1, value.size() - 1)))
        throw std::invalid_argument("Invalid value format");
    float val = std::atof(value.substr(1, value.size() - 1).c_str());
    if (val < 0)
        throw std::invalid_argument("Invalid value format");
    else if (val > 1000)
        throw std::invalid_argument("Invalid value format");
    return 0;
}

bool    check_pipe(std::string &line)
{
    int pipe_count = 0;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i] == '|')
            pipe_count++;
        if (i == line.size() - 2 && line[i] == '|')
            throw std::invalid_argument("Invalid input line");
    }
    if (pipe_count != 1)
        throw std::invalid_argument("Invalid input line");
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
        if (i == line.size() - 1 && line[i] == ',')
            throw std::invalid_argument("Invalid input file");
        if(i == line.size() - 1 && line[i] == '.')
            throw std::invalid_argument("Invalid input file");
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
            throw std::invalid_argument("Invalid input file");
        }
        lines[line.substr(0, 10)] = std::atof(line.substr(11, line.size() - 11).c_str());
    }
    file.close();
    return lines;
}

BitcoinExchange::BitcoinExchange()
{
    try
    {
        values = get_value_input("data.csv", values);
//        for(std::map<std::string, float>::iterator it = values.begin(); it != values.end(); it++)
//        {
//            std::cout << it->first << " " << it->second << std::endl;
//        }
    }
    catch (std::exception &e)
    {
        throw std::invalid_argument("Invalid input file");
    }
}

void    BitcoinExchange::makeExchange(const std::string &date, const std::string &value)
{
    long double val = std::atof(value.c_str());
    std::map <std::string, float>::iterator it = values.find(date);
    std::cout << std::fixed << std::setprecision(2);
    if(it != values.end())
    {
        std::cout << date << "  " << val << "btc =|=|=> " << it->second * val << " dinheiro" << std::endl;
    }
    else
    {
        it = this->values.lower_bound(date + " ");
        if (it != this->values.begin())
            it--;
        std::cout << date << "  " << val << "btc =|=|=> " << it->second * val << " dinheiro" << std::endl;
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