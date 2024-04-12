//
// Created by ldiogo on 12-04-2024.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

bool is_all_digit(const char *str)
{
    int i = -1;

    while(str[++i] != '\0')
    {
        if (!std::isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
            std::cout << str << std::endl;
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

int main(int argc, char **argv)
{
    std::stack<int> stack;
    std::stringstream ss = std::stringstream(argv[1]);
    std::string str;
    ss = std::stringstream(argv[1]);
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
