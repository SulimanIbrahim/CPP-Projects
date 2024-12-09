#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_num = 0;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}

Fixed::Fixed(const Fixed & copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed & copy)
{
    if (this != &copy)
    _num = copy._num;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
    _num = raw;
}
