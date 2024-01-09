//
// Created by ldiogo on 1/9/24.
//

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
    Fixed::value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    Fixed::value = roundf(value * (1 << Fixed::fractional));
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    Fixed::value = value << Fixed::fractional;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return Fixed::value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    Fixed::value = raw;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &fixed)
        Fixed::value = fixed.getRawBits();
    return *this;
}

float Fixed::toFloat() const
{
    return (float)Fixed::value / (1 << Fixed::fractional);
}

int Fixed::toInt() const
{
    return Fixed::value >> Fixed::fractional;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
