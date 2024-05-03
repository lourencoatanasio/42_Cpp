//
// Created by ldiogo on 12-04-2024.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cctype>
#include <cstdlib>

bool is_all_digit(const char *str)
{
    int i = -1;

    while(str[++i] != '\0')
    {
        if (!std::isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
            return false;
        }
    }
    return true;
}

bool is_operator(char c)
{
    if (c != '+' && c != '-' && c != '*' && c != '/')
        return false;
    return true;
}

int checker(char **argv)
{
    std::stringstream ss(argv[1]);
    std::string str;
    int number = 0;
    int oper = 0;
    while(ss >> str)
    {
        if (!is_all_digit(str.c_str()) || (is_operator(str[0]) && str.size() != 1))
            return 1;
        if (is_operator(str[0]))
            oper++;
        else
            number++;
    }
    if (number - oper != 1)
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <expression>" << std::endl;
        return 1;
    }
    std::stack<int> stack;
    std::stringstream ss(argv[1]);
    std::string str;
    if(checker(argv))
    {
        std::cout << "Invalid argument" << std::endl;
        return 1;
    }
    while(ss >> str)
    {
        if(is_operator(str[0]))
        {
            if(stack.size() < 2)
            {
                std::cout << "Invalid argument" << std::endl;
                return 1;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if(str[0] == '-')
                stack.push(b - a);
            else if(str[0] == '+')
                stack.push(b + a);
            else if(str[0] == '*')
                stack.push(b * a);
            else if(str[0] == '/' && a != 0)
                stack.push(b / a);
            else {
                std::cout << "Error" << std::endl;
                return 1;
            }
        }
        else
        {
            if(!is_all_digit(str.c_str()))
            {
                std::cout << "Invalid argument" << std::endl;
                return 1;
            }
            stack.push(std::atoi(str.c_str()));
        }
    }
    std::cout << stack.top() << std::endl;
    return 0;
}
