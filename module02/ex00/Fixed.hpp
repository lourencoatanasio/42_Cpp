//
// Created by ldiogo on 1/9/24.
//

#ifndef INC_42_CPP_FIXED_HPP
#define INC_42_CPP_FIXED_HPP


class Fixed {
private:
    int					value;
    static const int	fractional = 8;
public:
    Fixed();
    Fixed(const Fixed &fixed);
    ~Fixed();
    Fixed &operator=(const Fixed &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#endif //INC_42_CPP_FIXED_HPP
