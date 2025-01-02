#include "Dog.hpp"

Dog::Dog(){
    this->_type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy){
    *this = copy;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy){
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy){
        this->_type = copy._type;
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Bark" << " " << std::endl;
}
