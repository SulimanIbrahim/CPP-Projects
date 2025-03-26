#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &copy) : Aanimal(copy){
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = copy._type;
    this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy){
    std::cout << "Cat assignation operator called" << std::endl;
    if (this != &copy){
        delete this->brain;
        this->brain = new Brain(*copy.brain);
        this->_type = copy._type;
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meow... 🐈" << " " << std::endl;
}

void Cat::setIdea(int index, std::string idea){
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const{
    return this->brain->getIdea(index);
}