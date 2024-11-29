#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->ayhaja = 0;
    this->ayhaja1 = 1;
    this->ayhaja2 = 2;
    this->ayhaja3 = 3;
}
Fixed::Fixed(int num)
{
    std::cout << "int called\n";
    this->ayhaja = num << 8; // raw bits
    std::cout << "int ayhaja = \n" << this->ayhaja;
    this->ayhaja1 = 1;
    this->ayhaja2 = 2;
    this->ayhaja3 = 3;
}
Fixed::Fixed(float num)
{
    std::cout << "float called\n";
    this->ayhaja = roundf(num * (1 << 8));
    float res = (float)this->ayhaja / (1 << 8);
    std::cout << "float res = " << res << std::endl;
    this->ayhaja1 = 1;
    this->ayhaja2 = 2;
    this->ayhaja3 = 3;
}
Fixed::~Fixed()
{
}


Fixed::Fixed(const Fixed & copy)
{
    *this = copy;

}

Fixed &Fixed::operator=(const Fixed & copy)
{
    std::cout << "here\n";
    this->ayhaja = copy.ayhaja;
    this->ayhaja1 = copy.ayhaja1;
    this->ayhaja2 = copy.ayhaja2;
    this->ayhaja3 = copy.ayhaja3;
    return (*this);
}


void Fixed::setAyhaja(int num)
{
    this->ayhaja = num;
}
void Fixed::setAyhaja1(int num)
{
    this->ayhaja1 = num;
}
void Fixed::setAyhaja2(int num)
{
    this->ayhaja2 = num;
}
void Fixed::setAyhaja3(int num)
{
    this->ayhaja3 = num;
}


int Fixed::getAyhaja(void)
{
    return (this->ayhaja);
}
int Fixed::getAyhaja1(void)
{
    return (this->ayhaja1);
}
int Fixed::getAyhaja2(void)
{
    return (this->ayhaja2);
}
int Fixed::getAyhaja3(void)
{
    return (this->ayhaja3);
}


std::ostream& operator<<(std::ostream& os, Fixed& obj)
{
    os << "getAyhaja = " << obj.getAyhaja() << "\n";
    os << "getAyhaja1 = " << obj.getAyhaja1() << "\n";
    os << "getAyhaja2 = " << obj.getAyhaja2() << "\n";
    os << "getAyhaja3 = " << obj.getAyhaja3() << "\n";    
    return (os);
}
