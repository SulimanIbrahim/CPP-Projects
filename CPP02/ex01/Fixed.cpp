#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_num = 0;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->_num = num << this->_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->_num = roundf(num * (1 << _bits));
}

Fixed::Fixed(const Fixed & copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed & copy)
{
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &copy)
        this->_num = copy._num;
    return (*this);
}


int Fixed::getRawBits(void) const
{
    return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
    this->_num = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_num / (1 << 8));
}

int Fixed::toInt( void ) const
{
    return (this->_num >> this->_bits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& data)
{
    output << data.toFloat();
    return (output);
}

