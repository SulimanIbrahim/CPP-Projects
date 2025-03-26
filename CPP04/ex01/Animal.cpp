#include "Animal.hpp"

Animal::Animal() : _type(""){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &copy){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy){
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &copy){
        this->_type = copy._type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const{  
   std::cout << "Hmmmm, What sound do I make ?" << std::endl;
}
