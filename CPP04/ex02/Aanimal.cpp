#include "Aanimal.hpp"

Aanimal::Aanimal() : _type(""){
    std::cout << "Aanimal constructor called" << std::endl;
}

Aanimal::~Aanimal(){
    std::cout << "Aanimal destructor called" << std::endl;
}

Aanimal::Aanimal(const Aanimal &copy){
    std::cout << "Aanimal copy constructor called" << std::endl;
    *this = copy;
}

Aanimal &Aanimal::operator=(const Aanimal &copy){
    std::cout << "Aanimal assignation operator called" << std::endl;
    if (this != &copy){
        this->_type = copy._type;
    }
    return (*this);
}

std::string Aanimal::getType() const
{
    return this->_type;
}
