#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _num;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed & copy);
        Fixed &operator=(const Fixed & copy);
        Fixed operator+(const Fixed & rhs) const;
        Fixed operator-(const Fixed & rhs) const;
        Fixed operator*(const Fixed & rhs) const;
        Fixed operator/(const Fixed & rhs) const;
        bool operator>(const Fixed & rhs) const;
        bool operator<(const Fixed & rhs) const;
        bool operator>=(const Fixed & rhs) const;
        bool operator<=(const Fixed & rhs) const;
        bool operator==(const Fixed & rhs) const;
        bool operator!=(const Fixed & rhs) const;
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed & a, Fixed & b);
        static const Fixed &min(const Fixed & a, const Fixed & b);
        static Fixed &max(Fixed & a, Fixed & b);
        static const Fixed &max(const Fixed & a, const Fixed & b);

        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& output,  const Fixed& data);

#endif