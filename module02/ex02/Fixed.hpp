//
// Created by ldiogo on 1/9/24.
//

#ifndef INC_42_CPP_FIXED_HPP
#define INC_42_CPP_FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

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
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &rhs);
#endif //INC_42_CPP_FIXED_HPP
