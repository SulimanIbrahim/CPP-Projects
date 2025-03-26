#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog(){
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Aanimal(copy){
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = copy._type;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy){
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy){
        delete this->brain;
        this->brain = new Brain(*copy.brain);
        this->_type = copy._type;
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Hoofff... 🦮🐶" << " " << std::endl;
}

void Dog::setIdea(int index, std::string idea){
    this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const{
    return this->brain->getIdea(index);
}