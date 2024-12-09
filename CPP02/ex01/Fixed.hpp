#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _num;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed(const Fixed & copy);
        Fixed &operator=(const Fixed & copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

};

std::ostream& operator<<(std::ostream& output,  const Fixed& data);

#endif