#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

#include <iostream>

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
         ~Dog();
        void makeSound(void) const;
        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
};

#endif
