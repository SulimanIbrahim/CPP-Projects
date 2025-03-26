#include "Brain.hpp"


Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy) {
    if (this != &copy) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}


void Brain::setIdea(int index, std::string idea) {
    if (index < 0 || index >= 100)
    {
        std::cout << "Index out of range" << std::endl;
        return ;
    }
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index < 0 || index >= 100)
    {
        std::cout << "Index out of range" << std::endl;
        return NULL;
    }   
    return this->ideas[index];
}

