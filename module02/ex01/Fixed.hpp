//
// Created by ldiogo on 1/9/24.
//

#ifndef INC_42_CPP_FIXED_HPP
#define INC_42_CPP_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int					value;
    static const int	fractional = 8;
public:
    Fixed(const int value);
    Fixed(const float value);
    Fixed();
    Fixed(const Fixed &fixed);
    ~Fixed();
    Fixed &operator=(const Fixed &fixed);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);
#endif //INC_42_CPP_FIXED_HPP
